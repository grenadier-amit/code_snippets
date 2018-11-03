#include<bits/stdc++.h>

void pre_kmp(char *pat,int m,int *lps)
{
	int i,j=0;
	lps[0]=0;

	for(i=1;i<m;i++)
	{
		if(pat[i]==pat[j])
		{
			lps[i]=j+1;
			i++,j++;
		}
		else
		{
			if(j!=0)
				j=lps[j-1];
			else
			{
				lps[i]=0;
				i++;
			}
		}
	}
}

int main()
{
	char s[10000];
	scanf("%s",s);
	int lps[10000];
	pre_kmp(s,strlen(s),lps);
	for(int i=0;i<strlen(s);i++)
		printf("%d- %d\n",i,lps[i]);
	return 0;
}
