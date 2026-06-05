#include<stdio.h>
typedef struct{
	char name[21];
	int score,id;
}S;
int cmp(const void *a,const void *b)
{S *s1=(S*)a,*s2=(S*)b;
 if(s1->score!=s2->score)
 {return s2->score-s1->score;
 }else
  {return s1->id-s2->id;
  }
}
main()
{int n,i;
 scanf("%d",&n);
 S s[n];
 for(i=0;i<n;i++)
 {getchar();
  scanf("%[^,],%d",s[i].name,&s[i].score);
  s[i].id=i;
 }
 qsort(s,n,sizeof(S),cmp);
 for(i=0;i<n;i++)
 {printf("%s,%d\n",s[i].name,s[i].score);
 }
return 0;
}
