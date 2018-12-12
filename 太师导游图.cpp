#include<stdio.h>
#include<iostream>
#include<windows.h>
#include<string>
#include<iomanip>
#include"guide.h"
#include"stack.h"
#define oo 10000
using namespace std;
int X=0,Y=0;
void initgrah(int maxvex,G &g)  //��ʼ���������
{

    for(int i=0; i<maxvex; i++)
        for(int j=0; j<maxvex; j++)
            g.arc[i][j]=oo;
    g.arc[0][1]=g.arc[1][0]=30;
    g.arc[0][2]=g.arc[2][0]=25;
    g.arc[0][22]=g.arc[22][0]=200;
    g.arc[0][6]=g.arc[6][0]=60;

    g.arc[1][2]=g.arc[2][1]=20;
    g.arc[1][11]=g.arc[11][1]=300;

    g.arc[3][21]=g.arc[21][3]=150;
    g.arc[3][4]=g.arc[4][3]=10;

    g.arc[4][5]=g.arc[5][4]=10;
    g.arc[4][21]=g.arc[21][4]=150;

    g.arc[5][6]=g.arc[6][5]=20;
    g.arc[5][21]=g.arc[21][5]=20;

    g.arc[7][16]=g.arc[16][7]=10;
    g.arc[7][14]=g.arc[14][7]=20;

    g.arc[8][9]=g.arc[9][8]=10;
    g.arc[8][10]=g.arc[10][8]=100;

    g.arc[9][15]=g.arc[15][9]=20;
    g.arc[9][11]=g.arc[11][9]=100;
    g.arc[9][12]=g.arc[12][9]=10;

    g.arc[10][13]=g.arc[13][10]=100;
    g.arc[10][14]=g.arc[14][10]=200;

    g.arc[11][22]=g.arc[22][11]=150;

    g.arc[12][22]=g.arc[22][12]=40;

    g.arc[13][15]=g.arc[15][13]=15;

    g.arc[14][17]=g.arc[17][14]=150;
    g.arc[14][15]=g.arc[15][14]=75;

    g.arc[15][16]=g.arc[16][15]=50;
    g.arc[15][22]=g.arc[22][15]=50;

    g.arc[16][17]=g.arc[17][16]=75;
    g.arc[16][18]=g.arc[18][16]=150;

    g.arc[17][20]=g.arc[20][17]=100;

    g.arc[18][23]=g.arc[23][18]=10;

    g.arc[19][23]=g.arc[23][19]=10;

    g.arc[20][23]=g.arc[23][20]=20;

    g.arc[21][22]=g.arc[22][21]=100;
    g.arc[21][23]=g.arc[23][21]=50;


}

void floyd(G &g, int maxvex)
{
	int k;

	for (int i = 0; i < maxvex; i++)
	for (int j = 0; j < maxvex; j++)
		{
		if(g.arc[i][j]==oo)
            path[i][j]=-1;
            else  path[i][j]=i;
		d[i][j] = g.arc[i][j];
		}
    for(int i=0; i<maxvex; i++)
            d[i][i]=0;


    for ( k = 0; k < maxvex; k++)
    {
        for (int i = 0; i < maxvex; i++)
            for (int j = 0; j < maxvex; j++)
                if ((d[i][k] + d[k][j]) < d[i][j])
                {
                    d[i][j] = d[i][k] + d[k][j];
                     path[i][j]=path[k][j];

                }
    }
}
void display(int i, int j)  /*��ӡ���������·�������·��*/
{
   Stack s;
    SetPosition(2,20);
	int a, b,temp;
	a = i;
	b = j;
	printf("��Ҫ��ѯ������������·���ǣ� \n\n");
	fflush(stdin);
	if (i < j)
	{
        //printf("%d", b);
		 //  cout << adj[b/6][b%6].name << " <<<";
		s.push(b);
		while (i!=j)
		{
            //printf("<--%d", path[i][j]);
			//cout << adj[path[i][j]/6][path[i][j]%6].name<<" <<<";
           s.push(path[i][j]);
			if (i < j)
				j = path[i][j];
			else
				i = path[j][i];
		}
		//printf("<-%d\n\n", a);
	   	//cout << adj[a/6][a%6].name << " ";
          // s.push(a);
       while(s.base!=s.top){
        cout<< adj[s.gettop()/6][s.gettop()%6].name <<">>>";
        s.pop();
        }

		printf("\n�����Ҫ�ߣ� %d ��\n\n", d[a][b]);
	}
	else
	{
		cout << adj[a/6][a%6].name << " >>>";
		while (i!=j)
		{
			cout << adj[path[j][i]/6][path[j][i]%6].name<<" >>>";
			//printf("-->%d", path[i][j]);
			if (i < j)
				j = path[i][j];
			else
				i = path[j][i];
		}
		//cout << adj[b/6][b%6].name << " ";
		printf("\n���·���ǣ� %d �ס�\n\n", d[a][b]);
	}
}
void showmenu()
{

    SetConsoleTitle("̫ԭʦ��ѧԺ����ϵͳv3.0");
    printf("                 ******************************************         \n");
    printf("                 *----------------------------------------*         \n");
    printf("                 |    ��ӭ����̫ԭʦ��ѧԺ����ϵͳv1.0    |         \n");
    printf("                 *----------------------------------------*         \n");
    printf("                 ******************************************         \n");
    printf("\n");
}
void showgn()
{
    printf("                             0.����Աģʽ\n");
    printf("                             1.�鿴У԰ƽ��ͼ\n");
    printf("                             2.Ѱ·��ѯ\n");
    printf("                             3.�˳�\n");
}
void showmapandinformation()
{
    system("cls");
    SetPosition(0,2);
    printf("||| ********* WSAD �����������ң�P��:����·����ѯ  B��:����������********** |||\n");
    printf("||| ****************��ѯ��ʽΪ������λ�ñ��+�ո�+Ŀ�ĵر��*************** |||\n");
    printf("_______________________________________________________________________________________________");
    SetPosition(0,3);
    for(int i=0; i<4; i++)
    {
        cout<<endl<<endl;
        for(int j=0; j<6; j++)
        {
            if(X==j&&Y==i)SetColor(5,15);

            printf("%s",adj[i][j].name);
            SetColor(10,0);

        }
    }
    cout<<endl<<endl;;
   printf("______________________________________________________________________________________________");

    SetPosition(12,15);
    printf("%s",adj[Y][X].instruction);
    for(int i=0; i<4; i++)
    {
        SetPosition(0,15+i);
        printf("|");
        SetPosition(88,15+i);
        printf("|");
    }
    cout<<endl;
  printf("______________________________________________________________________________________________");

}

void seachshorttravel()
{
    SetPosition(2,25);
    cout<<"�����������յ���(�س�������):";
    int first,last;
    cin>>first>>last;
    display(first,last);
    cin.get();
}

int main()
{
    G g;
    initgrah(adjmax, g);         //��ʼ��������
   //floyd(g,adjmax);             //floyd�㷨�����о����໥��������·��
    int choose;
    SetColor(10,0);         //��������ǰ��Ϊ��ɫ������Ϊ��ɫ
   while(1)
    {
        system("cls");      //����
        showmenu();         //��ʾ����ϵͳ����
        showgn();           //��ʾ���ܲ˵�
        printf("����ѡ��:");
        cin>>choose;
        switch(choose)
        {
        case 2:
            system("cls");
            showmapandinformation();
            while(1)
            {
                while(1)
                {
                    char  key=getch();
                    switch(key)
                    {
                    case 'W':
                    case 'w':
                        Y--;
                        break;
                    case 'S':
                    case 's':
                        Y++;
                        break;
                    case 'A':
                    case 'a':
                        X--;
                        break;
                    case 'D':
                    case 'd':
                        X++;
                        break;
                    case 'p':
                    case 'P':
                        floyd(g,adjmax);
                        seachshorttravel();
                        break;
                    }
                    if(X>5)X=0;
                    if(X<0)X=5;
                    if(Y>3)Y=0;
                    if(Y<0)Y=3;
                    showmapandinformation(); //ˢ�� map and information
                    if((key=='b')||(key=='B'))break;

                }
                break;
            }

            break;
        case 1:
            while(1)
            {
                system("cls");
                MAP();
                system("pause");
                char k=getch();
                if(k)break;
            }
            break;
        case 3:
            exit(0);
            break;
        case 0:
            while(1)
            {   system("cls");
                printf("1.��ͨ·��\n");
                printf("2.����·��\n");
                printf("3.������һ��\n");
                cout<<"���������Ĳ���:"<<endl;
                int chose;
                cin>>chose;
                if(chose==1)
                {
                    int vi,vj,length;
                    cout<<"�������ͨ��·<vi,vj,length>"<<endl;
                    cin>>vi>>vj>>length;
                   g.arc[vj][vi]=g.arc[vi][vj]=length;
                    cout<<"�����ɹ�"<<endl;
                    system("pause");
                }
                if(chose==2)
                {
                    int vi,vj;
                     cout<<"������������·<vi,vj,oo>"<<endl;
                     cin>>vi>>vj;
                     g.arc[vj][vi]=g.arc[vi][vj]=oo;
                     cout<<"�����ɹ�"<<endl;
                     system("pause");
                }
                if(chose==3)break;
            }
            break;
        }
    }

    cin.get();
    return 0;
}
