///*
//Josh Welch
//CST-312
//Ceaser Cipher
//*/
//
//#include <iostream>
//#include <string>
//using namespace std;
//
//void CeaserEncrypt(int key, string &message)
//{
//	key %= 26;
//
//	for (int i = 0; i < message.length(); i++)
//	{
//		if (isalpha(message[i]))
//		{
//			for (int ii = 0; ii < key; ii++)
//			{
//				if (message[i] == 'z')
//				{
//					message[i] = 'a';
//				}
//				else if (message[i] == 'Z')
//				{
//					message[i] = 'A';
//				}
//				else
//				{
//					message[i]++;
//				}
//			}
//		}
//	}
//};
//
//void CeaserDecrypt(int key, string &message)
//{
//	key %= 26;
//
//	for (int i = 0; i < message.length(); i++)
//	{
//		if (isalpha(message[i]))
//		{
//			for (int ii = 0; ii < key; ii++)
//			{
//				if (message[i] == 'a')
//				{
//					message[i] = 'z';
//				}
//				else if (message[i] == 'A')
//				{
//					message[i] = 'Z';
//				}
//				else
//				{
//					message[i]--;
//				}
//			}
//		}
//	}
//};
//
//
//
//void main()
//{
//	int k,c,index;
//	string msg;
//
//	cout << "Enter a value for k: ";
//	cin >> k;
//	if (k < 1)
//	{
//		while (k < 1)
//		{
//			cout << "Please enter a value for k greater than zero: " << endl;
//			cin >> k;
//		}
//	}
//	cout << endl;
//	cout << "Enter 1 for encrpytion or 2 for decreption: ";
//	cin >> c;
//	if (c != 1||c!=2)
//	{
//		while (c != 1 && c != 2)
//		{
//			cout << "Please only enter 1 or 2 " << endl;
//			cin >> c;
//		}
//	}
//	cout << endl;
//	cin.ignore();
//	if (c == 1)
//	{
//		cout << "Enter message for encryption: "<<endl;
//		getline(cin, msg);
//		CeaserEncrypt(k, msg);
//		cout << "Encyrpted message: " << msg<<endl;
//	}
//	else
//	{
//		cout << "Enter message for decryption: " << endl;
//		getline(cin, msg);
//		CeaserDecrypt(k, msg);
//		cout << "Decrypted message: " <<msg<<endl;
//		
//	}
//
//
//}