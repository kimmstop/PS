int main()
{
	int a;
	scanf("%d", &a);
	for (int b = 1; b <= a; b++)
	{
		for (int c = 1; c <= b; c++)
		{
			printf("*");
		}
		printf("\n");
	}
}
