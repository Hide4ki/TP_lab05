#include "Keeper.h"

Keeper::Keeper(void)
{
	ConParts = new List<Conference*>;
	cout << "Object of class - Keeper" << endl << "Magic method - constructor without parameters" << endl;
}

Keeper::Keeper(ifstream &stream)
{
	ConParts = new List<Conference*>;
	LoadFromFile(stream);
	cout << "Object of class - Keeper" << endl << "Magic method - constructor with parameters" << endl;
}

Keeper::Keeper(const Keeper&myKeeper)
{
	ConParts = new List<Conference*>;
	*ConParts = *myKeeper.ConParts;
	cout << "Object of class - Keeper" << endl << "Magic method - constructor for copy" << endl;
}

Keeper::~Keeper(void)
{
	IteratorPtr<Conference*> i = ConParts->GetCorrectIterator();
	for(i->First(); !i->IsDone(); i->Next())
		delete i->CurrentItem();
	cout << "Object of class - Keeper" << endl << "Magic method - destructor" << endl;
	delete ConParts;
}

void Keeper::addObj(Conference *myConPart)
{
	ConParts->Append(myConPart);
}

void Keeper::deleteObj(Conference *myConPart)
{
	IteratorPtr<Conference*> i = ConParts->GetCorrectIterator();
	for(i->First(); !i->IsDone(); i->Next())
	{
		if(myConPart->getType() == i->CurrentItem()->getType())
			switch(myConPart->getType())
			{	
				case ADM:
					if(*((Administrator*)myConPart) == *((Administrator*)i->CurrentItem()))
					{
						ConParts->Remove(i->CurrentItem());
						delete i->CurrentItem();
						return;
					}
					break;
				case SPE:
					if(*((Speaker*)myConPart) == *((Speaker*)i->CurrentItem()))
					{
						ConParts->Remove(i->CurrentItem());
						delete i->CurrentItem();
						return;
					}
					break;
				case PRO:
					if(*((Program*)myConPart) == *((Program*)i->CurrentItem()))
					{
						ConParts->Remove(i->CurrentItem());
						delete i->CurrentItem();
						return;
					}
					break;
			}
	}
	throw MyException("This obj don't be in keeper");
}

bool Keeper::findObj(const Conference *myConPart)
{
	IteratorPtr<Conference*> i = ConParts->GetCorrectIterator();
	for(i->First(); !i->IsDone(); i->Next())
	{
		if(myConPart->getType() == i->CurrentItem()->getType())
			switch(myConPart->getType())
			{	
				case ADM:
					if(*((Administrator*)myConPart) == *((Administrator*)i->CurrentItem()))
						return true;
					break;
				case SPE:
					if(*((Speaker*)myConPart) == *((Speaker*)i->CurrentItem()))
						return true;
					break;
				case PRO:
					if(*((Program*)myConPart) == *((Program*)i->CurrentItem()))
						return true;
					break;
			}
	}
	return false;
}

void Keeper::LoadFromFile(ifstream&stream)
{
	int cnt;
	stream >> cnt;
	int t;
	AdministratorBilder newAB;
	SpeakerBilder newSB;
	ProgramBilder newPB;

	for(int i = 0; i<cnt; i++)
	{
		stream >> t;
		switch((TYPE)t)
		{
			case ADM:
				stream >> newAB;
				ConParts->Append(new Administrator(newAB));
				break;
			case SPE:
				stream >> newSB;
				ConParts->Append(new Speaker(newSB));
				break;
			case PRO:
				stream >> newPB;
				ConParts->Append(new Program(newPB));
				break;
		}
	}
}

void Keeper::SafeToFile(ofstream&stream)
{	
	stream << ConParts->Count() << endl;
	IteratorPtr<Conference*> i = ConParts->GetCorrectIterator();
	for(i->First(); !i->IsDone(); i->Next())
	{
		stream << i->CurrentItem()->getType() << endl;
		i->CurrentItem()->WriteInFile(stream);
	}
}