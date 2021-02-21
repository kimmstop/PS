#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>




using namespace std;

int seqlength, subseqlength, postoinsert;
int smallestgoodseq[80], goodseq[80];
int firstsubseq[40], secondsubseq[40];

void Makegoodseq();
bool Isprevnumequaltonumtoinsert(int postoinsert, int numtoinsert);
bool Isgoodseq(int curseqlength);
bool Isgoodseqateachsubseq(int subseqlength, int curseqlength);
void Settwosubseq(int firstsubseqstartpos, int secondsubseqstartpos, int subseqlength);
bool Isadjacentsubseqsame(int subseqlength);
void Updatesmallestgoodseq(int seqlength);	
	
int main()
{
	cin >> seqlength;
	fill(smallestgoodseq, smallestgoodseq + seqlength, 9);
	postoinsert=0;
	Makegoodseq();
}

void Makegoodseq()
{
	if(postoinsert == seqlength){
		Updatesmallestgoodseq(seqlength);
		postoinsert--;
		return;
	}
	for(int numtoinsert = 1; numtoinsert <= 3; numtoinsert++){
		if(Isprevnumequaltonumtoinsert(postoinsert, numtoinsert)){
			continue;
		}
		else{
			goodseq[postoinsert++] = numtoinsert;
		}
		
		
		if(Isgoodseq(postoinsert) == true){
			Makegoodseq();
		}
		else{
			postoinsert--;
		}
	}
	postoinsert--;
}

bool Isprevnumequaltonumtoinsert(int postoinsert, int numtoinsert)
{
	if(postoinsert == 0)
		return false;
	if(goodseq[postoinsert - 1] == numtoinsert)	
		return true;
	return false;
}


bool Isgoodseq(int curseqlength)
{
	for(int subseqlength = 2; subseqlength <= curseqlength/2; subseqlength++){
		if(Isgoodseqateachsubseq(subseqlength, curseqlength) == false){
			return false;
		}
	}
	return true;
}

bool Isgoodseqateachsubseq(int subseqlength, int curseqlength)
{
	int secondsubseqstartpos = curseqlength - subseqlength;
	int firstsubseqstartpos = secondsubseqstartpos - subseqlength;
	Settwosubseq(firstsubseqstartpos, secondsubseqstartpos, subseqlength);
		
	if(Isadjacentsubseqsame(subseqlength) == true){
		return false;
	}
	return true;
}

void Settwosubseq(int firstsubseqstartpos, int secondsubseqstartpos, int subseqlength)
{
	memcpy(firstsubseq, goodseq + firstsubseqstartpos, subseqlength * 4);
	memcpy(secondsubseq, goodseq + secondsubseqstartpos, subseqlength * 4);
}

bool Isadjacentsubseqsame(int subseqlength)
{
	if(memcmp(firstsubseq, secondsubseq, subseqlength * 4) == 0)
		return true;
	return false;
}

void Updatesmallestgoodseq(int seqlength)
{
	if(memcmp(smallestgoodseq, goodseq, seqlength * 4) > 0){
		memcpy(smallestgoodseq, goodseq, seqlength * 4);
		for(int i = 0; i < seqlength; i++){
			cout << smallestgoodseq[i];
		}
		exit(0);
	}
	

}

/* Isprevnumequaltonumtoinsert() 이 함수로 인해 전체적인
코드의 흐름이 깨지긴 했지만 함수 호출 과정을 조금이나마 줄일 수 있다.
가능한 모든 수열을 만들어 가면서 그 수열이 좋은 수열인지 아닌지
판단했다. 
처음에는 각 단계에서 가능한 모든 부분수열을 만들어서 비교를 했지만
시관초과가 걸렸다. 나중에 모든 부분수열을 굳이 만들 필요가 없고
새로넣은 값을 포함하는 부분수열만 만들면 된다는 것을 알게되었고
이 방법이 시간초과를 해결해 줄 것 같았지만 여전히 시간초과가 걸렸다.
다시 생각해보니 코드는 애초에 작은 수열부터 만들어 질 수 밖에 없다.
원래 코드는 굳이 모든 좋은 수열을 구하면서 가장 작은 수열을 업데이트 하는
방식이지만 가장 먼저 구한 좋은 수열이 좋은 수열 중 최소이며 정답이다.*/