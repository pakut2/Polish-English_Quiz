#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <cstdlib>
#include <vector>

using namespace std;

void add();
void database();
void quiz();
void del();
void baseAng();
void basePol();
void choseQuiz();
void quizPA();
void quizAP();
void del_word( string &, const string );

void menu()
{
	system("cls");
	int amount = 0;
	char choise;

	while(true)
	{
		cout << "NAUCZ SIE JEZYKA ANGIELSKIEGO!" << endl;
		cout << "------------------------------------" << endl;
		cout << "1. Przeglad slowek" << endl;
		cout << "2. Dodawanie slowek" << endl;
		cout << "3. Usuwanie slowek" << endl;
		cout << "4. Test" << endl;
		cout << "5. Zamknij program" << endl;

		cout << endl;
		choise = getch();

		switch(choise)
		{
			case '1': database(); break;
			case '2': add(); break;
			case '3': del(); break;
			case '4': choseQuiz(); break;
			case '5': exit(0); break;
			default: cout << "Nie ma takiej opcji w menu"; break;
		}
		cout << endl;
		getchar(); getchar();
		system("cls");
	}
}

void database()
{
    system("cls");

    char type;
	cout << "1. Slowa polskie" << endl;
	cout << "2. Slowa angielskie" << endl;
	cout << "3. Menu" << endl;

	type = getch();
	switch(type)
	{
		case '1': basePol(); break;
		case '2': baseAng(); break;
		case '3': menu(); break;
	}
}

void basePol()
{
    system("cls");
    string linia;
    fstream plik;
    plik.open("pol.txt", ios::in);

    if (plik.good()==false)
    {
        cout<<"Cos sie zapsulo i nie udalo sie otworzyc pliku";
        exit(0);
    }

    if(plik.good() == true)
    {
        while(!plik.eof())
        {
            getline(plik, linia);
            cout << linia << endl;
        }
        plik.close();
    }
    cout << "Aby kontynuowac, wcisnij dowolny klawisz \n";
    getch();
    system("cls");
    database();
}

void baseAng()
{
    system("cls");
    string linia;
    fstream plik;
    plik.open("ang.txt", ios::in);

    if (plik.good()==false)
    {
        cout<<"Cos sie zapsulo i nie udalo sie otworzyc pliku";
        exit(0);
    }

    if(plik.good() == true)
    {
        while(!plik.eof())
        {
            getline(plik, linia);
            cout << linia << endl;
        }
        plik.close();
    }
    cout << "Aby kontynuowac, wcisnij dowolny klawisz \n";
    getch();
    system("cls");
    database();
}

void add()
{
    system("cls");
    fstream pol, ang;
    cout << "Dopisywanie do quizu \n";
    pol.open("pol.txt", ios::out | ios::app);
    ang.open("ang.txt", ios::out | ios::app);
    if(pol.good() == true || ang.good() == true)
    {
        string pl, eng;

        cout << "Polskie slowo: ";
        cin >> pl;

        cout << "Angielskie slowo: ";
        cin >> eng;

        pol << pl << endl;
        ang << eng << endl;
        pol.close();
        ang.close();
    }
    cout << "Aby kontynuowac, wcisnij dowolny klawisz \n";
    getch();
    system("cls");
    menu();
}

void del()
{
    system("cls");
    cout << "Usuwanie slowek \n";
    vector < string > polski;
    vector < string > angielski;
    string pl, eng;
    ifstream pol;
    ifstream ang;
    pol.open( "pol.txt" );
    ang.open( "ang.txt" );

    if (pol.good()==false || ang.good()==false)
    {
        cout<<"Cos sie zapsulo i nie udalo sie otworzyc pliku";
        exit(0);
    }

    cout << "Podaj polski wyraz, ktory chcesz usunac: ";
    cin >> pl;

    cout << "Podaj angielski odpowiednik: ";
    cin >> eng;

    string temp, temp2;
    while( getline( pol, temp ) )
    {
        del_word( temp, pl );
        polski.push_back( temp );
    }
    pol.close();

    while( getline( ang, temp2 ) )
    {
        del_word( temp2, eng );
        angielski.push_back( temp2 );
    }
    ang.close();

    ofstream poll( "pol.txt" );
    ofstream angg( "ang.txt" );

    if (poll.good()==false || angg.good()==false)
    {
        cout<<"Cos sie zapsulo i nie udalo sie otworzyc pliku";
        exit(0);
    }

    for( unsigned i = 0; i < polski.size(); i++ )
         poll << polski.at( i ) << endl;

    poll.close();

    for( unsigned i = 0; i < angielski.size(); i++ )
         angg << angielski.at( i ) << endl;

    angg.close();

    cout << "Aby kontynuowac, wcisnij dowolny klawisz \n";
    getch();
    system("cls");
    menu();
}

void del_word( string & tekst, const string slowo )
{
    size_t n;
    if(( n = tekst.find( slowo ) ) != string::npos )
         tekst.erase( n, slowo.length() );
}

void choseQuiz()
{
    system("cls");

    char type;
	cout << "1. Quiz polsko-angielski" << endl;
	cout << "2. Quiz angielsko-polski" << endl;
	cout << "3. Menu" << endl;

	type = getch();
	switch(type)
	{
		case '1': quizPA(); break;
		case '2': quizAP(); break;
		case '3': menu(); break;
	}
}

void quizPA()
{
    system("cls");
    int pts = 0;
    string eng[1000];
    string pl[1000];
    int tmp = 0;
    int tmp2 = 0;
    int tmp3 = 0;

    fstream pol, ang;
    pol.open("pol.txt",ios::in);
    ang.open("ang.txt",ios::in);

    if (pol.good()==false || ang.good()==false)
    {
        cout<<"Cos sie zapsulo i nie udalo sie otworzyc pliku";
        exit(0);
    }

    while (!pol.eof())
    {
        pol >> pl[tmp];
        tmp++;
    }

    while (!ang.eof())
    {
        ang >> eng[tmp2];
        tmp2++;
    }

    pol.close();
    ang.close();

    for (int i=0; i<=tmp2-2; i++)
    {
        cout << "Quiz polsko-angielski" << endl;
        cout << "Podaj odpowiednik slowa w jezyku angielskim: " << endl;
        cout << pl[i] << endl;

        string odp;
        cout<<"Twoja odpowiedz: ";
        cin>>odp;

        transform(odp.begin(), odp.end(), odp.begin(), ::tolower);

        if (odp==eng[i])
        {
            cout << "Poprawna odpowiedz" << endl;
            pts++;
        }
        else
        {
            cout << "Bledna odpowiedz. Poprawna odpwiedz to: "<< eng[i] <<endl;
        }

        cout << "Aby kontynuowac, wcisnij dowolny klawisz \n";

        getch();
        system("cls");

    }

    float tmp2_1 = tmp2;
    float pts_1 = pts;
    float per = (pts_1/(tmp2_1-1))*100;

    cout << "Koniec quizu. Poprawne odpowiedzi: " << pts << endl;
    cout << "Wynik procentowy: " << per << "%" << endl;

    if(per==0)
    	cout << "Wszystko zle! Zarty sobie robisz?" << endl;
    else if(per>0 && per<=25)
    	cout << "Z takim wynikiem, to do zawodowki co najwyzej" << endl;
    else if(per>25 && per<=50)
    	cout << "Z takim wynikiem, to mozna isc kopac rowy!" << endl;
    else if(per>50 && per <=75)
    	cout << "No tak srednio bym powiedzial" << endl;
    else if(per>75 && per<90)
    	cout << "Nawet dobry wynik" << endl;
    else if(per>=90 && per<100)
    	cout << "Bardzo dobry wynik!" << endl;
    else if(per==100)
    	cout << "Wszystko dobrze!" << endl;

    cout << "Aby kontynuowac, wcisnij dowolny klawisz \n";
    getch();
    menu();
}

void quizAP()
{
    system("cls");
    int pts = 0;
    string eng[100];
    string pl[100];
    int tmp = 0;
    int tmp2 = 0;
    int tmp3 = 0;

    fstream pol, ang;
    pol.open("pol.txt",ios::in);
    ang.open("ang.txt",ios::in);

    if (pol.good()==false || ang.good()==false)
    {
        cout<<"Cos sie zapsulo i nie udalo sie otworzyc pliku";
        exit(0);
    }

    while (!pol.eof())
    {
        pol >> pl[tmp];
        tmp++;
    }

    while (!ang.eof())
    {
        ang >> eng[tmp2];
        tmp2++;
    }

    pol.close();
    ang.close();

    for (int i=0; i<=tmp2-2; i++)
    {
        cout << "Quiz angielsko-polski" << endl;
        cout << "Podaj odpowiednik slowa w jezyku polskim: " << endl;
        cout << eng[i] << endl;

        string odp;
        cout<<"Twoja odpowiedz: ";
        cin>>odp;

        transform(odp.begin(), odp.end(), odp.begin(), ::tolower);

        if (odp==pl[i])
        {
            cout << "Poprawna odpowiedz" << endl;
            pts++;
        }
        else
        {
            cout << "Bledna odpowiedz. Poprawna odpwiedz to: "<< pl[i] <<endl;
        }

        cout << "Aby kontynuowac, wcisnij dowolny klawisz \n";

        getch();
        system("cls");

    }

    float tmp2_1 = tmp2;
    float pts_1 = pts;
    float per = (pts_1/(tmp2_1-1))*100;

    cout << "Koniec quizu. Poprawne odpowiedzi: " << pts << endl;
    cout << "Wynik procentowy: " << per << "%" << endl;

    if(per==0)
    	cout << "Wszystko zle! Zarty sobie robisz?" << endl;
    else if(per>0 && per<=25)
    	cout << "Z takim wynikiem, to do zawodowki co najwyzej" << endl;
    else if(per>25 && per<=50)
    	cout << "Z takim wynikiem, to mozna isc kopac rowy!" << endl;
    else if(per>50 && per <=75)
    	cout << "No tak srednio bym powiedzial" << endl;
    else if(per>75 && per<90)
    	cout << "Nawet dobry wynik" << endl;
    else if(per>=90 && per<100)
    	cout << "Bardzo dobry wynik!" << endl;
    else if(per==100)
    	cout << "Wszystko dobrze!" << endl;

    cout << "Aby kontynuowac, wcisnij dowolny klawisz \n";
    getch();
    menu();
}

int main()
{
    menu();

    return 0;
}
