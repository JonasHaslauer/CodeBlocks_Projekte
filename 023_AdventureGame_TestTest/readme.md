# Quiz: Adventure Game V1 (ADV1) with tests
---
File: MAB-ADV1-TESTS-xml.zip


## 1. install and run ADV1
----
You have:
* main.cpp
* CGame.cpp, CGame.h
* CRoom.cpp, CRoom.h
* world.txt

Compile with: 
* `g++ main.cpp CGame.cpp CRoom.cpp -o main.exe`

Run with: 
* `./main.exe`



## 2. Study XML and tinyxml
----
Unzip and study
* `unzip demo_adventuregame_fragen_tinyxml.zip`
* `cd demo_adventuregame_fragen_tinyxml`
* `g++ tinyxml2.cpp adv_questions.cpp -o adv_questions.exe`
* `./adv_questions.exe`

See File: **adv_questions.xml**
~~~
<?xml version="1.0" encoding="UTF-8"?>
<fragen>
<frage>
<fragentext>
BEISPIEL: SINGLE-CHOICE-Frage
Objekte, die nicht mehr benötigt werden, müssen gelöscht
werden. Dazu wird eine boolsche Variable remove verwendet. 
In welcher Klasse wird Sie definiert?
a) Sprite b) Rocket c) GamePanel d) Explosion
</fragentext>
<loesungstext>a</loesungstext>
<punkte>10</punkte>
</frage>

<frage>
<fragentext>
BEISPIEL: SINGLE-CHOICE-Frage
Das tatsächliche Löschen der Objekte erfolgt in
a) GamePanel.doLogic() b) Rocket.doLogic 
</fragentext>
<loesungstext>a</loesungstext>
<punkte>10</punkte>
</frage>


<frage>
<fragentext>
BEISPIEL: MULTIPLE-CHOICE: mit , trennen
Von Ihnen programmierte Klassen im Spiel:
a) GamePanel b) Rocket c) Image d) Movable
</fragentext>
<loesungstext>a,b</loesungstext>
<punkte>20</punkte>
</frage>


<frage>
<fragentext>
BEISPIEL: SINGLE-LÜCKEN-Frage: 
Was gehört statt ??? geschrieben.
public class GamePanel extends JPanel ??? Runnable{...}
</fragentext>
<loesungstext>implements</loesungstext>
<punkte>10</punkte>
</frage>


<frage>
<fragentext>
BEISPIEL: MULTIPLE_LÜCKEN-Frage: Antworten mit , trennen
Was gehört statt ??? geschrieben.
Thema: Threads erzeugen
public class GamePanel ... Runnable{
	...
	public void ??? (){ 
		// hier läuft der Thread
		...
	}
	...
	
	public void init(){
		Thread t= new Thread(???);
		t.start();
	}
}
</fragentext>
<loesungstext>run,this</loesungstext>
<punkte>20</punkte>
</frage>

<frage>
<fragentext>
BEISPIEL: WAHR od. FALSCH Frage: 
wahr bzw. falsch eingeben: 
Java unterstützt Mehrfachevererbung
</fragentext>
<loesungstext>falsch</loesungstext>
<punkte>10</punkte>
</frage>


</fragen>
~~~



## 3. ADV1 with tests
---
In File **world.txt** extend the room *Eingang* with the `<test>` tag. For example

~~~
<Eingang>
_____________________________________________________________________
   Ja, endlich. Sie haben es gefunden. Ein unheimliches Haus. 
   Eine geheimnisvolle Person aus dem Jenseits hat ihnen
   eine schreckliche Nachricht ueberbracht.

   Ihr Freund wird von dunklen Maechten in einem grossen Haus
   festgehalten. Sie muessen ihn retten. Ja, wirklich, das sind
   sie ihm schuldig.
   Also worauf warten Sie, gehen Sie ins Haus.

   ABER BEVOR SIE INS HAUS KÖNNEN, MÜSSEN SIE DEN TEST MIT MEHR ALS 50% BESTEHEN!!!!

   STARTE den Test mit dem Befehl test. 

   (hilfe bzw. ?)
_____________________________________________________________________*
<nord> Mitte
<ost>  None
<sued> None
<west> None
<test> cpp-test.xml
~~~


## 4. Class CRoom with tests
In class **CRoom** add 
1. a member data: `vector<Question*> questions_;`
2. a member data: `string testFilename_;`
3. a member function: `string getTestFilename(void)const{ return testFilename; }`
4. extend `void CRoom::readRoomInfo(string& aRoom){...}` to read the testFilename
5. a member function `int CRoom::doTest(string testFilename, string username);`
	* reads all questions from testFilename into the vector questions_.
	* (hint: maybe useful: testFilename.c_str())
	* execute the test
		* ask the questions and 
		* get the answer from the user
		* calculate the points 
	* write the following information to cout
~~~
	Username: _____________
	Testname: _____________
	Erreichte Punkte: _____
	Gesamt Punkte: ________
~~~

In class **CGAME::start()** add
```
else if(strInput == "test"){
	string username;
	cout << "\nEnter your username: ";
	cin>> username;

	m_Room->doTest(m_Room->getTestFilename(), username);

	return ;			
}

```

