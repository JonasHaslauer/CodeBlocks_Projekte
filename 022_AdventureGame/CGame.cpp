#include "CGame.h"
#include <iostream>
#include <string>
#include <cstdlib>  // exit()
#include <stdio.h>
#include <stdlib.h>

using namespace std;


CGame::CGame(const char* pFilename)
{
    fin.open(pFilename);

    if(fin.fail())
    {
        cerr << "   Fehler: Konnte " << pFilename << " nicht finden" << endl;
        exit (1);
    }

    m_Room= new CRoom(fin, &items, &monsters);

    playerScore = 0;

    string buffer;
    //Get first room
    string startRoom;
    fin>>buffer>>startRoom;

    //Get Player info
    string name;
    int health, damage;
    fin>>buffer>>buffer>>name;  //read name
    fin>>buffer>>health;        //read health
    fin>>buffer>>damage;        //read damage
    player = new CPlayer(name, health, damage);

    m_Room->readRoomInfo(startRoom);
    m_Room->display();
    this->displayCommands();

}

void CGame::start()
{
    string aRoom;


    //Gameloop
    while(1)
    {
        cout << m_Room->getCurrentRoom() <<":> ";

        //Userinput
        string strInput = "";
        cin >> strInput;

        system("clear");

        if(strInput == "look")
        {
            m_Room->display();
            m_Room->displayItems();
        }
        else if(strInput == "lookAt")
        {
            vector<string> showable = m_Room->getShowable();
            cout << "What do you want to look at?" << endl;
            cin >> strInput;

            //Look for the item
            vector<string>::iterator it;
            for(it = showable.begin(); it != showable.end(); it++)
            {
                if((*it) == strInput)
                {
                    m_Room->displayShowable(strInput);
                }
            }
        }
        else if(strInput == "pickUp")
        {
            bool pickedUp = false;
            cout << "What do you want to pick up? ('all' picks up every Item in the room)" << endl;
            cin >> strInput;


            vector<CItem*>::iterator it;
            if(strInput == "all")
                //Look for all Items in a current room + if they are already picked up or not
            {
                for(it = items.begin(); it != items.end(); it++)
                {
                    if((*it)->getRoom() == m_Room->getCurrentRoom() && !(*it)->isOwned())
                    {
                        pickedUp = true;
                        (*it)->setOwned(true);
                        playerScore += (*it)->getValue();
                        cout << "You picked up " << (*it)->getName() << ". " << (*it)->getValue() << " Points were added." << endl;
                    }
                }
            }
            else
                //Look for a certain Item in current room + if it is already picked up or not
            {
                for(it = items.begin(); it != items.end(); it++)
                {
                    if((*it)->getName() == strInput && (*it)->getRoom() == m_Room->getCurrentRoom() && !(*it)->isOwned())
                    {
                        pickedUp = true;
                        (*it)->setOwned(true);
                        playerScore += (*it)->getValue();
                        cout << "You picked up " << strInput << ". " << (*it)->getValue() << " Points were added." << endl;
                    }
                }
            }
            if(!pickedUp)
            {
                cout << "Can't pick up Item <" << strInput << ">." << endl;
            }
        }
        else if(strInput == "info")
        {

            cout << "---------------------------------INFOTABLE---------------------------------" << endl << endl;
            cout << "Player - " << player->getName() << "\t\t" << "Health - " << player->getHealth() << "\t\t" << "Damage - " << player->getDamage() << endl << endl;

            if(playerScore > 0)
            {
                cout << "Your points: " << playerScore << endl << endl;
                cout << "<Itemname>\tRoom in which it was found\tPoints" << endl;
                cout << "--------------------------------------------------------------------------" << endl;
                vector<CItem*>::iterator it;
                for(it = items.begin(); it != items.end(); it++)
                {
                    if((*it)->isOwned())
                    {
                        cout << "<" << (*it)->getName() << ">\t";
                        if((*it)->getName().size() < 7)
                            cout << "\t" << (*it)->getRoom() << "\t\t\t" << (*it)->getValue() << endl;
                        else
                            cout << (*it)->getRoom() << "\t\t\t" << (*it)->getValue() << endl;
                    }
                }
            }
            else
            {
                cout << "You do not own any items yet." << endl;;
            }
        }
        else if(strInput == "north")
        {
            aRoom= m_Room->getRoomNorth();
            m_Room->moveto(aRoom);
            m_Room->display();
            this->displayCommands();
        }
        else if(strInput == "east")
        {
            aRoom= m_Room->getRoomEast();
            m_Room->moveto(aRoom);
            m_Room->display();
            this->displayCommands();
        }
        else if(strInput == "south")
        {
            aRoom= m_Room->getRoomSouth();
            m_Room->moveto(aRoom);
            m_Room->display();
            this->displayCommands();
        }
        else if(strInput == "west")
        {
            aRoom= m_Room->getRoomWest();
            m_Room->moveto(aRoom);
            m_Room->display();
            this->displayCommands();
        }
        else if(strInput == "end")
        {
            return;
        }
        else if(strInput == "help" || strInput == "?")
        {
            this->displayCommands();
        }
        else
        {
            cout << "Command unknown" << endl << endl << "Use ? to show commands or look to look at the room you are currently in." << endl;
        }
    }
}

CGame::~CGame()
{
    fin.close();
    delete m_Room;
}

void CGame::displayCommands()
{
    cout  << "Befehle: look, lookAt, pickUp, info, north, east, south, west, help, ?, end" << endl << endl;
}

