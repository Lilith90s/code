#include "stdafx.h"
#include "Folder.h"


Folder::Folder()
{
}


Folder::~Folder()
{
}

void Folder::addMsg(Message *m)
{
	Msgs.insert(m);
}

void Folder::remMsg(Message *m)
{
	Msgs.insert(m);
}
