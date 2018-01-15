#include<iostream>
using namespace std;
typedef struct {
                int content[100][100];
                int top;
               }stiva;

int n;
stiva S;

int solutie(stiva S)
{
if(S.top==n)  return 1;
return 0;
}

int tipar(stiva S)
{
cout<<endl;
for(int i=1;i<=S.top;i++) cout<<S.content[i]<<" ";
}

int init(stiva *S)
{
(*S).content[(*S).top]=0;
}

int succesor(stiva *S)
{
if (((*S).content[(*S).top])<n )
        {
          (*S).content[(*S).top]++;
          return 1;
        }
return 0;
}
int valid(stiva S)
{
for(int i=1;i<S.top;i++) {
                if  (S.content[i]==S.content[S.top]) return 0;
                          }
return 1;
}
int bktrit(stiva S)
{
S.top=1;
init(&S);
while (S.top>=1)
  {
   int am,este;
   do {
       am=succesor(&S);
       este=valid(S);
      } while (!( (am&&este)||(!am)));
   if (am) {
        if(solutie(S)) {
                        tipar(S);
                         }
              else {
                    S.top++;
                    init(&S);
                   }
            }
        else {
            S.top--;
             }


   }
}



int main()
{
cout<<"n=";cin>>n;
bktrit(S);
return 0;
}
