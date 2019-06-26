#include "pch.h"
#include <iostream>
#include <fstream>
#include <assert.h>
#include <clocale>
#include <Windows.h>
#include "C:\Users\Михаил\Desktop\Учёба\3.2\Технологии программирования\Лаба5\ConsoleApplication2\ConsoleApplication1\Source.cpp"
#include "C:\Users\Михаил\Desktop\Учёба\3.2\Технологии программирования\Лаба5\ConsoleApplication2\ConsoleApplication1\struct.h"
#include "CppUnitTest.h"
#include <vector>

using namespace std;
using namespace types;
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

		//Ввод по каждому
		//Выводы по каждому
		//Подсчёт гласных
		//Функция сортировки
		//Фильтрованный вывод
		//Какие тесты бывают

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
		void testfiles(ifstream &in, ifstream &in_test)
		{
			vector<string> strings1;
			string test;
			while (!getline(in, test).eof())
				strings1.push_back(test);
			strings1.push_back(test);

			vector<string> strings2;
			string out;
			while (!getline(in_test, out).eof())
				strings2.push_back(out);
			strings2.push_back(out);

			for (int i = 0; i < out.length(); i++)
			{
				Assert::AreEqual(strings1[i], strings2[i]);
			}
		}
		bool isdigit(int int_test)
		{
			int mass[10] = { { 0 }, { 1 },{ 2 }, { 3 }, { 4 }, { 5 }, { 6 }, { 7 }, { 8 }, { 9 } };
			for (int i = 0; i < 10; i++)
			{
				if (int_test == mass[i])
				{
					return true;
				}
			}
			return false;
		}

	public:
		//Ввод
		//Тестирование ввода(InGame)
		TEST_METHOD(TestInGame)
		{
			ifstream ifst("test_game.txt");
			if (!ifst)
			{
				cout << "No input file found!" << endl;
				exit(1);
			}
			vector<string> string1;
			string1.push_back("1");
			string1.push_back("США Тёмный_рыцарь Нолан");

			vector<string> string2;
			string out;
			while (!getline(ifst, out).eof())
			{
				string2.push_back(out);
			}
			string2.push_back(out);

			for (int i = 0; i < string2.size(); i++)
			{
				Assert::AreEqual(string1[i], string2[i]);
			}
		}

		//Тестирование ввода(InCartoon)
		TEST_METHOD(TestInCartoon)
		{
			ifstream ifst("test_cartoon.txt");
			if (!ifst)
			{
				cout << "No input file found!" << endl;
				exit(1);
			}
			vector<string> string1;
			string1.push_back("2");
			string1.push_back("Польша Лунтик 2");

			vector<string> string2;
			string out;
			while (!getline(ifst, out).eof())
			{
				string2.push_back(out);
			}
			string2.push_back(out);

			for (int i = 0; i < string2.size(); i++)
			{
				Assert::AreEqual(string1[i], string2[i]);
			}

		}

		//Тестирование ввода(InDoc)
		TEST_METHOD(TestInDoc)
		{
			ifstream ifst("test_doc.txt");
			if (!ifst)
			{
				cout << "No input file found!" << endl;
				exit(1);
			}
			vector<string> string1;
			string1.push_back("3");
			string1.push_back("Россия История_мира 1999");

			vector<string> string2;
			string out;
			while (!getline(ifst, out).eof())
			{
				string2.push_back(out);
			}
			string2.push_back(out);

			for (int i = 0; i < string2.size(); i++)
			{
				Assert::AreEqual(string1[i], string2[i]);
			}

		}

		//Подсчёт гласных
		TEST_METHOD(TestVowelGame)
		{
			ifstream ifst("test_game.txt");
			if (!ifst)
			{
				cout << "No input file found!" << endl;
				exit(1);
			}
			container c;
			film* fm;
			int key;
			ifst >> key;

			fm = new game;
			fm->InData(ifst);
			int coutnofvowel = fm->Vowel();
			if (!isdigit(coutnofvowel))
			{
				cout << "Wrong type of variable" << endl;
			}
			int test = 4;

			Assert::AreEqual(coutnofvowel, test);
		}

		TEST_METHOD(TestVowelCartoon)
		{
			ifstream ifst("test_cartoon.txt");
			if (!ifst)
			{
				cout << "No input file found!" << endl;
				exit(1);
			}
			container c;
			film* fm;
			int key;
			ifst >> key;

			fm = new game;
			fm->InData(ifst);
			int coutnofvowel = fm->Vowel();
			if (!isdigit(coutnofvowel))
			{
				cout << "Wrong type of variable" << endl;
			}
			int test = 2;

			Assert::AreEqual(coutnofvowel, test);
		}

		TEST_METHOD(TestVowelDoc)
		{
			ifstream ifst("test_doc.txt");
			if (!ifst)
			{
				cout << "No input file found!" << endl;
				exit(1);
			}
			container c;
			film* fm;
			int key;
			ifst >> key;
			
			fm = new game;
			fm->InData(ifst);
			int coutnofvowel =fm->Vowel();
			if (!isdigit(coutnofvowel))
			{
				cout << "Wrong type of variable" << endl;
			}
			int test = 6;

			Assert::AreEqual(coutnofvowel, test);
		}

		//Сортировка
		TEST_METHOD(TestInSort)
		{
			ifstream ifst("in.txt");
			if (!ifst)
			{
				cout << "No input file found!" << endl;
				exit(1);
			}
			ofstream ofst("out.txt", ios::trunc);
			container c;
			c.In(ifst);
			c.Out(ofst);

			ifstream in("out.txt");
			if (!in)
			{
				cout << "No input file found!" << endl;
				exit(1);
			}
			ifstream in_test("out_test.txt");
			if (!in_test)
			{
				cout << "No input file found!" << endl;
				exit(1);
			}

			testfiles(in, in_test);
		}

		//Вывод
		//Тестирование ввода(InGame)
		TEST_METHOD(TestOutGame)
		{
			ifstream ifst("test_game.txt");
			if (!ifst)
			{
				cout << "No input file found!" << endl;
				exit(1);
			}
			ofstream ofst("test_game_out.txt", ios::trunc);
			container c;
			c.In(ifst);
			c.Out(ofst);

			ifstream in("test_game_out.txt");
			if (!in)
			{
				cout << "No input file found!" << endl;
				exit(1);
			}
			ifstream in_test("game_out.txt");
			if (!in_test)
			{
				cout << "No input file found!" << endl;
				exit(1);
			}
			testfiles(in, in_test);
			
		}

		//Тестирование ввода(InCartoon)
		TEST_METHOD(TestOutCartoon)
		{
			ifstream ifst("test_cartoon.txt");
			if (!ifst)
			{
				cout << "No input file found!" << endl;
				exit(1);
			}
			ofstream ofst("test_cartoon_out.txt", ios::trunc);
			container c;
			c.In(ifst);
			c.Out(ofst);

			ifstream in("test_cartoon_out.txt");
			if (!in)
			{
				cout << "No input file found!" << endl;
				exit(1);
			}
			ifstream in_test("cartoon_out.txt");
			if (!in_test)
			{
				cout << "No input file found!" << endl;
				exit(1);
			}
			
			testfiles(in, in_test);

		}

		//Тестирование ввода(InDoc)
		TEST_METHOD(TestOutDoc)
		{
			ifstream ifst("test_doc.txt");
			if (!ifst)
			{
				cout << "No input file found!" << endl;
				exit(1);
			}
			ofstream ofst("test_doc_out.txt", ios::trunc);
			container c;
			c.In(ifst);
			c.Out(ofst);

			ifstream in("test_doc_out.txt");
			if (!in)
			{
				cout << "No input file found!" << endl;
				exit(1);
			}
			ifstream in_test("doc_out.txt");
			if (!in_test)
			{
				cout << "No input file found!" << endl;
				exit(1);
			}
			
			testfiles(in, in_test);

		}

		
		//OutGame
		TEST_METHOD(TestOnlyGame)
		{
			ifstream ifst("in.txt");
			if (!ifst)
			{
				cout << "No input file found!" << endl;
				exit(1);
			}
			ofstream ofst("outfilter.txt", ios::trunc);
			container c;
			c.In(ifst);
			c.OutGame(ofst);

			ifstream in("outfilter.txt");
			if (!in)
			{
				cout << "No input file found!" << endl;
				exit(1);
			}
			ifstream in_test("outfilter_test.txt");
			if (!in_test)
			{
				cout << "No input file found!" << endl;
				exit(1);
			}

			testfiles(in, in_test);
		}

	};
}
