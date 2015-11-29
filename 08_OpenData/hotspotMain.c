#include <stdio.h>
#include <stdlib.h>

#include "hotspot.h"

int main() {
	FILE* fcsv;
	FILE* ftxt;

	char sLine[MAXLEN + 1];
	char lat[MAXLEN + 1];
	char lon[MAXLEN + 1];
	char title[MAXLEN + 1];
	char description[MAXLEN + 1];

    //system("wget \"http://data.stadt-salzburg.at/geodaten/wfs?service=WFS&version=1.1.0&request=GetFeature&srsName=urn:x-ogc:def:crs:EPSG:4326&outputFormat=csv&typeName=ogdsbg:wlanhotspot\" -O wlanhotspot.csv");

	//Fileopening
	fcsv = fopen("./wlanhotspot.csv", "rt");
	if (fcsv == NULL) {
		printf("Fehler beim lesen der Datei");
		exit(1);
	}
	ftxt = fopen("./textfile.txt", "wt");
	if (ftxt == NULL) {
		printf("Fehler beim beschreiben der Datei");
		exit(2);
	}

	//Skip first line
	fgets(sLine, MAXLEN, fcsv);

	//Write first line
	fprintf(ftxt, "lat\tlon\ttitle\tdescription\ticon\ticonSize\ticonOffset\n");

	//Read and write
	while (fgets(sLine, MAXLEN, fcsv) != NULL) {
		//Split
		getLat(sLine, lat);
		getLon(sLine, lon);
		getTitle(sLine, title);
		getDescription(sLine, description);

		//Write
		printf("Writing: %s\t%s\t%s\t%s\n", lat, lon, title, description);
		fprintf(ftxt, "%s\t%s\t%s\t <a href=\"%s\">%s</a> \n", lat, lon, title, description, description);
	}

	fclose(ftxt);
	fclose(fcsv);

	return 0;
}
