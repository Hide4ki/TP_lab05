#include <iostream>
#include <fstream>
#include <string>
#include <limits>
#include "MyException.h"
#include "WorkEnd.h"
#include "Conference.h"
#include "Keeper.h"
#include "AdministratorBuilder.h"
#include "ProgramBuilder.h"
#include "SpeakerBuilder.h"

using namespace std;

typedef enum {ADD, DEL, SAFE, LOAD, END} COMMAND;

int main(void)
{
	cout << "Good day!=)" << endl;
	Keeper *myKeeper = new Keeper;
	Administrator *A = 0;
	Conference *myConf = 0;
	AdministratorBuilder *aBild = 0;
	ProgramBuilder *pBild = 0;
	SpeakerBuilder *sBild = 0;
	int cnt = 0;
	while(1)
	{
		try
		{
			int command;
			int obj;
			int method;
			ifstream *fin;
			ofstream *fout;
			string name;
			cout << "Input command(" << ADD << "- add obj; " << DEL << " - del obj; " << SAFE << " - safe state in file; " << LOAD << " - load state in file; " << END << " - end work.)" << endl;
			cin >> command;
			while (cin.fail())
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "Error!!! Input don't correct, repeat input!!" << endl;
				cin >> command;
			}
			cnt++;
			switch((COMMAND)command)
			{
			case ADD:
				while(1)
				{
					try
					{
						cout << "Selected add" << endl;
						cout << "Select object for add("<<ADM<<" - admin; "<<SPE<<" - speaker; "<<PRO<<" - program):";
						cin >> obj;
						while (cin.fail())
						{
							cin.clear();
							cin.ignore(numeric_limits<streamsize>::max(), '\n');
							cout << "Error!!! Input don't correct, repeat input!!" << endl;
							cin >> obj;
						}
						switch((TYPE)obj)
						{
						case ADM:
							aBild = new AdministratorBuilder;
							try
							{
								string tmp;
								while(1)
								{
									cout << "Select param for set("<<\
									ANAME<<" - name; "<<\
									ASURNAME<<" - surname; "<<\
									AFATHERNAME<<" - father name; "<<\
									APOSITION<<" - position; "<<\
									ARESPONSIBLE<<" - responsible; "<<\
									AFIN<<" - input all void field; "<<\
									AENDBILD<<" - End work): ";
									cin >> method;
									while (cin.fail())
									{
										cin.clear();
										cin.ignore(numeric_limits<streamsize>::max(), '\n');
										cout << "Error!!! Input don't correct, repeat input!!" << endl;
										cin >> method;
									}
									switch((ABILD)method)
									{
									case ANAME:
										cout << "Input name admin: ";
										cin >> tmp;
										aBild->SetName(tmp);
										break;
									case ASURNAME:
										cout << "Input surname admin: ";
										cin >> tmp;
										aBild->SetSurname(tmp);
										break;
									case AFATHERNAME:
										cout << "Input father name admin: ";
										cin >> tmp;
										aBild->SetFatherName(tmp);
										break;
									case APOSITION:
										cout << "Input position admin: ";
										cin >> tmp;
										aBild->SetPosition(tmp);
										break;
									case ARESPONSIBLE:
										cout << "Input responsible admin: ";
										cin >> tmp;
										aBild->SetResponsible(tmp);
										break;
									case AFIN:
										cin >> *aBild;
										break;
									case AENDBILD:
										throw WorkEnd();
										break;
									default:
										throw MyException("Error!!! Input don't correct, repeat input!!");
									}
								}
							}
							catch(WorkEnd &e)
							{
								cout << "Admin Build fin"<< endl;
							}		
							catch(MyException e)
							{
								cout << "Error: " << e << endl; 
							}
							myKeeper->addObj(new Administrator(*aBild));
							delete aBild;
							break;
						case SPE:
							sBild = new SpeakerBuilder;
							try
							{
								string tmp;
								while(1)
								{
									cout << "Select param for set("\
										<<SNAME<<" - name;"\
										<<SSURNAME<<" - surname; "\
										<<SFATHERNAME<<" - father name; "\
										<<SORG<<" - organization; "\
										<<SLEC<<" - lection; "\
										<<SANNO<<" - annotation; "
										<<SFIN<<" - input all void field; "\
										<<SENDBILD<<" - End work): ";
									cin >> method;
									while (cin.fail())
									{
										cin.clear();
										cin.ignore(numeric_limits<streamsize>::max(), '\n');
										cout << "Error!!! Input don't correct, repeat input!!" << endl;
										cin >> method;
									}
									switch((SBILD)method)
									{
									case SNAME:
										cout << "Input name speaker: ";
										cin >> tmp;
										sBild->SetName(tmp);
										break;
									case SSURNAME:
										cout << "Input surname speaker: ";
										cin >> tmp;
										sBild->SetSurname(tmp);
										break;
									case SFATHERNAME:
										cout << "Input father name speaker: ";
										cin >> tmp;
										sBild->SetFathername(tmp);
										break;
									case SORG:
										cout << "Input organisation speaker: ";
										cin >> tmp;
										sBild->SetOrganization(tmp);
										break;
									case SANNO:
										cout << "Input annotation speaker: ";
										cin >> tmp;
										sBild->SetAnnotation(tmp);
										break;
									case SLEC:
										cout << "Input lecture speaker: ";
										cin >> tmp;
										sBild->SetLecture(tmp);
										break;
									case SFIN:
										cin >> *sBild;
										break;
									case SENDBILD:
										throw WorkEnd();
										break;
									default:
										throw MyException("Error!!! Input don't correct, repeat input!!");
									}
								}
							}
							catch(WorkEnd &e)
							{
								cout << "Speaker Build fin"<< endl;
							}		
							catch(MyException e)
							{
								cout << "Error: " << e << endl; 
							}
							myKeeper->addObj(new Speaker(*sBild));
							delete sBild;
							break;
						case PRO:
							pBild = new ProgramBuilder;
							try
							{
								string tmp;
								time_t tmp1;
								Presetion tmp2; 
								while(1)
								{
									cout << "Select param for set("\
										<<PNAME<<" - name;"\
										<<PDATE<<" - date; "\
										<<PADDPRESENT<<" - add presentation; "\
										<<PFIN<<" - input all void field; "\
										<<PENDBILD<<" - End work): ";
									cin >> method;
									while (cin.fail())
									{
										cin.clear();
										cin.ignore(numeric_limits<streamsize>::max(), '\n');
										cout << "Error!!! Input don't correct, repeat input!!" << endl;
										cin >> method;
									}
									switch((PBILD)method)
									{
									case PNAME:
										cout << "Input name program: ";
										cin >> tmp;
										pBild->SetName(tmp);
										break;
									case PDATE:
										cout << "Input date program: " <<endl;
										cin >> tmp1;
										pBild->SetDate(tmp1);
										break;
									case PADDPRESENT:
										cin >> tmp2;
										pBild->AddPresent(tmp2);
										break;
									case PFIN:
										cin >> *pBild;
										break;
									case PENDBILD:
										throw WorkEnd();
										break;
									default:
										throw MyException("Error!!! Input don't correct, repeat input!!");
									}
								}
							}
							catch(WorkEnd &e)
							{
								cout << "Program Build fin"<< endl;
							}		
							catch(MyException e)
							{
								cout << "Error: " << e << endl; 
							}
							myKeeper->addObj(new Program(*pBild));
							delete pBild;
							break;
						default:
							throw MyException("Error!!! Input don't correct!!");
						}
					}
					catch(MyException e)
					{
						cout << e << endl; 
						break;
					}
				}
				break;
			case DEL:
				while(1)
				{
					try
					{
						cout << "Selected del" << endl;
						cout << "Select object for del(0 - admin; 1 - speaker; 2 - program):";
						cin >> obj;
						while (cin.fail())
						{
							cin.clear();
							cin.ignore(numeric_limits<streamsize>::max(), '\n');
							cout << "Error!!! Input don't correct, repeat input!!" << endl;
							cin >> obj;
						}
						switch((TYPE)obj)
						{
						case ADM:
							aBild = new AdministratorBuilder;
							try
							{
								string tmp;
								while(1)
								{
									cout << "Select param for set obj whitch will delete("<<\
									ANAME<<" - name; "<<\
									ASURNAME<<" - surname; "<<\
									AFATHERNAME<<" - father name; "<<\
									APOSITION<<" - position; "<<\
									ARESPONSIBLE<<" - responsible; "<<\
									AFIN<<" - input all void field; "<<\
									AENDBILD<<" - End work): ";
									cin >> method;
									while (cin.fail())
									{
										cin.clear();
										cin.ignore(numeric_limits<streamsize>::max(), '\n');
										cout << "Error!!! Input don't correct, repeat input!!" << endl;
										cin >> method;
									}
									switch((ABILD)method)
									{
									case ANAME:
										cout << "Input name admin: ";
										cin >> tmp;
										aBild->SetName(tmp);
										break;
									case ASURNAME:
										cout << "Input surname admin: ";
										cin >> tmp;
										aBild->SetSurname(tmp);
										break;
									case AFATHERNAME:
										cout << "Input father name admin: ";
										cin >> tmp;
										aBild->SetFatherName(tmp);
										break;
									case APOSITION:
										cout << "Input position admin: ";
										cin >> tmp;
										aBild->SetPosition(tmp);
										break;
									case ARESPONSIBLE:
										cout << "Input responsible admin: ";
										cin >> tmp;
										aBild->SetResponsible(tmp);
										break;
									case AFIN:
										cin >> *aBild;
										break;
									case AENDBILD:
										throw WorkEnd();
										break;
									default:
										throw MyException("Error!!! Input don't correct, repeat input!!");
									}
								}
							}
							catch(WorkEnd &e)
							{
								cout << "Admin Build fin"<< endl;
							}		
							catch(MyException e)
							{
								cout << "Error: " << e << endl; 
							}
							A = new Administrator(*aBild);
							myKeeper->deleteObj(A);
							delete A;
							break;
						case SPE:
							sBild = new SpeakerBuilder;
							try
							{
								string tmp;
								while(1)
								{
									cout << "Select param for set obj whitch will delete("\
										<<SNAME<<" - name;"\
										<<SSURNAME<<" - surname; "\
										<<SFATHERNAME<<" - father name; "\
										<<SORG<<" - organization; "\
										<<SLEC<<" - lection; "\
										<<SANNO<<" - annotation; "
										<<SFIN<<" - input all void field; "\
										<<SENDBILD<<" - End work): ";
									cin >> method;
									while (cin.fail())
									{
										cin.clear();
										cin.ignore(numeric_limits<streamsize>::max(), '\n');
										cout << "Error!!! Input don't correct, repeat input!!" << endl;
										cin >> method;
									}
									switch((SBILD)method)
									{
									case SNAME:
										cout << "Input name speaker: ";
										cin >> tmp;
										sBild->SetName(tmp);
										break;
									case SSURNAME:
										cout << "Input surname speaker: ";
										cin >> tmp;
										sBild->SetSurname(tmp);
										break;
									case SFATHERNAME:
										cout << "Input father name speaker: ";
										cin >> tmp;
										sBild->SetFathername(tmp);
										break;
									case SORG:
										cout << "Input organisation speaker: ";
										cin >> tmp;
										sBild->SetOrganization(tmp);
										break;
									case SANNO:
										cout << "Input annotation speaker: ";
										cin >> tmp;
										sBild->SetAnnotation(tmp);
										break;
									case SLEC:
										cout << "Input lecture speaker: ";
										cin >> tmp;
										sBild->SetLecture(tmp);
										break;
									case SFIN:
										cin >> *sBild;
										break;
									case SENDBILD:
										throw WorkEnd();
										break;
									default:
										throw MyException("Error!!! Input don't correct, repeat input!!");
									}
								}
							}
							catch(WorkEnd &e)
							{
								cout << "Speaker Build fin"<< endl;
							}		
							catch(MyException e)
							{
								cout << "Error: " << e << endl; 
							}
							myKeeper->deleteObj(new Speaker(*sBild));
							delete sBild;
							break;
						case PRO:
							pBild = new ProgramBuilder;
							try
							{
								Presetion tmp2;						
								string tmp;
								time_t tmp1;
								while(1)
								{
									cout << "Select param for set obj whitch will delete("\
										<<PNAME<<" - name;"\
										<<PDATE<<" - date; "\
										<<PADDPRESENT<<" - add presentation; "\
										<<PFIN<<" - input all void field; "\
										<<PENDBILD<<" - End work): ";
									cin >> method;
									while (cin.fail())
									{
										cin.clear();
										cin.ignore(numeric_limits<streamsize>::max(), '\n');
										cout << "Error!!! Input don't correct, repeat input!!" << endl;
										cin >> method;
									}
									switch((PBILD)method)
									{
									case PNAME:
										cout << "Input name program: ";
										cin >> tmp;
										pBild->SetName(tmp);
										break;
									case PDATE:
										cout << "Input date program: " << endl;
										cin >> tmp1;
										pBild->SetDate(tmp1);
										break;
									case PADDPRESENT:
										cin >> tmp2;
										pBild->AddPresent(tmp2);
										break;
									case PFIN:
										cin >> *pBild;
										break;
									case PENDBILD:
										throw WorkEnd();
										break;
									default:
										throw MyException("Error!!! Input don't correct, repeat input!!");
									}
								}
							}
							catch(WorkEnd &e)
							{
								cout << "Program Build fin"<< endl;
							}		
							catch(MyException e)
							{
								cout << "Error: " << e << endl; 
							}
							myKeeper->deleteObj(new Program(*pBild));
							delete pBild;
							break;
						
						
						
						default:
							throw MyException("Error!!! Input don't correct, repeat input!!");
						}
					}
					catch(MyException e)
					{
						cout << e << endl; 
						break;
					}
				}
				break;
			case SAFE:
				cout << "Selected safe" << endl;
				cout << "Input file name for safe" << endl;
				cin >> name;
				fout = new ofstream(name);
				if (!*fout)
					throw MyException("File not available!!!");
				myKeeper->SafeToFile(*fout);
				delete fout;
				break;
			case LOAD:
				cout << "Selected load" << endl;
				cout << "Input file name for load" << endl;
				cin >> name;
				fin = new ifstream(name);
				if (!*fin)
					throw MyException("File not available!!!");
				myKeeper->LoadFromFile(*fin);
				delete fin;
				break;
			case END:
				throw new WorkEnd(cnt);
				break;
			default:
				throw MyException("Error!!! Input don't correct, repeat input!!");
			}
		}
		catch(MyException e)
		{
			cout << "Error: " << e << endl; 
		}
		catch(WorkEnd *e)
		{
			cout << *e << endl;
			delete e;
			break;
		}
		catch(...)
		{
			cout << "Error!!! Input don't correct, repeat input!!" << endl;
		}
	}
	delete myKeeper;
	system("pause");
	return 0;
}