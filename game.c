#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define AS(x)  (sizeof(x) / sizeof((x)[0]))

int menu();
int game(char *name);
int cards();
int running = 1;
int card[54];
int player1[20];
int player2[20];
int player3[20];
int getCards();
int rmCard(int index, int list[]);
int showCard(int index, int list[]);
int cardSize(int list[]);
int draw(char *ins, char *mess);
int gameON = 1;
int sort(int list[]);
char cr1[16] = "Unknown";
char cr2[16] = "Unknown";
char cr[16] = "Unknown";
int roleDecision();
int decision(int a);
int cardType(int list[]);
int dou(int a, int b);
int tri(int a, int b, int c);
int qua(int a, int b, int c, int d);
int pen(int a, int b, int c, int d, int e);
int pro(int list[]);
int proList[12];
int initial();
int next;
int loop();

int main(int argc, char **argv){

	printf("Welcome to Flight With The Landlord\nVersion: 0.0.1\n\n");
	
	while(running == 1){
		menu();
	}
	

	return 0;
}



int menu(){
	printf("Enter a choice:\n1. Start the game\n2. Rules Description\n3. Quit\n");
	int m;
	scanf("%d", &m);
	if(m == 1 || m == 2 || m == 3){
		switch(m){
			case 1:
				printf("What is you nickname: \n");
				char name[16];
				scanf("%15s", name);
				printf("Alright, %s, let start!\n", name);
				game(name);
			
			
				return 0;
			case 2:
				printf("The game rule is:\nThere are 3 player(1 Landlord,2 Farmers), and 54 cards\n4 different signs Heart, Spade, Club, Diamond;\n13 different number(Small to Big) 3,4,5,6,7,8,9,10,J,Q,K,A,2;\nand two jokers(biger than number cards): Big and Small;\nThe rules of game:\n1. Farmers are a team and need beat with the landlord. Landlord will have 3 more cards than others.\n2.Before the start, the player had got the smallest card could decide that he wants to get the landlord.\nAlso other could grab it if the first one give up to grab after one round.(only once round)\nThe Rule of Cards:\n1. There is NO order between the signs.(only compare the numbers)\n2. The player could skip thier turn or dicard cards\n3. the cards which discarded by player have to be [larger than] and [the same type of] cards from last player until nobody's cards are larger than you(they all skip)\nThe Type of the Cards:\n1.Solo(e.g Heart A ....)\n2.Pair(Heart A|Dimond A ....)\n3.Trio(only compare the the trio part)\n3.1. only Trio(e.g. Heart A|Dimond A| Club A ....)\n3.2. Trio with Solo(e.g. Heart A|Dimond A| Club A|Dimond 5 ....)\n3.3. Trio with Pair(e.g. Heart A|Dimond A| Club A|Dimond 5|Club 5)\n4. Chain[at least 5 cards](e.g. ___ 3 - ___ A(Not inc. 2))\n5. Bomb[four cards with same number or two jokers(Biggest)](e.g. Big and Small jokers or Heart A|Dimond A| Club A|Spade A)\n-end-rule of cards-\nwhen one player has discarded all cards. and the team, in which he is, will win\n\n");
				return 0;
			case 3:
				running = 0;
				printf("Thank you for playing Fight With The LandLord!\n");
				return 0;
		}
	}
	else{
		printf("Invalid Input Try Again!");
		return 0;
	}	
	return 0;
	
}

int game(char *name){
	initial();
	cards();
	printf("Now, The game is on!\nFirst, You will get 17 Random Cards\n");
	getCards();
	sort(player1);
	sort(player2);
	sort(player3);
	loop();
	
	
	return 0;
}

int loop(){
	int rd = roleDecision();
	

	return 0;
}

int initial(){
	for(int i = 0; i < 54; i++){
		card[i] = 0;
	}
	for(int i = 0; i < 20; i++){
		player1[i] = 0;
		player2[i] = 0;
		player3[i] = 0;
	}
	cr1[16] = *"Unknown";
	cr2[16] = *"Unknown";
	cr[16] = *"Unknown";
	return 0;
	
}
int cardType(int list[]){
	int length = cardSize(list);
	if(length == 1){
		return 1;
	}
	else if(length == 2){
		if((list[0] == 53 && list[1] == 54) || (list[0] == 54 && list[1] == 53)){
			return 4;
		}		
		else if(dou(list[0],list[1]) == 1){
			return 2;
		}
		else{
			return 0;
		}
		
	}
	else if(length == 3){
		if(tri(list[0], list[1], list[2]) == 1){
			return 3;
		}
		else{
			return 0;
		}
	}
	else if(length == 4){
		if(qua(list[0], list[1],list[2],list[3]) == 1){
			return 4;
		}	
		else if(qua(list[0], list[1],list[2],list[3]) == 2){
			return 5;
		}
		else{
			return 0;
		}
	}
	else if(length == 5){
		if(pen(list[0],list[1],list[2],list[3],list[4]) == 1){
			return 6;
		}
		else if(pro(list) == 1){
			return 7;
		}
		else{
			return 0;
		}
		
	}
	else if(length == 6){
		if(pro(list) == 1){
			return 8;
		}
		else{
			return 0;
		}
	}
	else if(length == 7){
		if(pro(list) == 1){
			return 9;
		}
		else{
			return 0;
		}
	}
	else if(length == 8){
		if(pro(list) == 1){
			return 10;
		}
		else{
			return 0;
		}
	}
	else if(length == 9){
		if(pro(list) == 1){
			return 11;
		}
		else{
			return 0;
		}
	}
	else if(length == 10){
		if(pro(list) == 1){
			return 12;
		}
		else{
			return 0;
		}
	}
	else if(length == 11){
		if(pro(list) == 1){
			return 13;
		}
		else{
			return 0;
		}
	}
	else if(length == 12){
		if(pro(list) == 1){
			return 14;
		}
		else{
			return 0;
		}
	}
	else{
		return 0;
	}
}
int pro(int list[]){
	int i;
	for(i = 0 ; i < 12; i++){
		proList[i] = 0;
	}
	int j;
	for(j = 0; j < cardSize(list); j++){
		proList[j] = list[j];
	}
	
	sort(proList);
	int a;
	int t;
	for(t = 0; t < cardSize(proList)-1; t++){
		if(proList[t]%4 == 1){
			if((proList[t]+4 == proList[t+1]) || (proList[t]+5 == proList[t+1]) || (proList[t]+6 == proList[t+1]) || (proList[t]+7 == proList[t+1])){
				a = 1;
			}
			else{
				return 0;
			}
		}
		else if(proList[t]%4 == 2){
			if((proList[t]+3 == proList[t+1]) || (proList[t]+4 == proList[t+1]) || (proList[t]+5 == proList[t+1]) || (proList[t]+6 == proList[t+1])){
				a = 1;
			}
			else{
				return 0;
			}
		}
		else if(proList[t]%4 == 3){
			if((proList[t]+2 == proList[t+1]) || (proList[t]+3 == proList[t+1]) || (proList[t]+4 == proList[t+1]) || (proList[t]+5 == proList[t+1])){
				a = 1;
			}
			else{
				return 0;
			}
		}
		else if(proList[t]%4 == 0){
			if((proList[t]+1 == proList[t+1]) || (proList[t]+2 == proList[t+1]) || (proList[t]+3 == proList[t+1]) || (proList[t]+4 == proList[t+1])){
				a = 1;
			}
			else{
				return 0;
			}
		}
	}
	
	return a;
	
}
int pen(int a, int b, int c, int d, int e){
	if((tri(a,b,c) == 1 && dou(d,e) == 1) || (tri(a,b,d) == 1 && dou(b,e) == 1) || (tri(a,b,d) == 1 && dou(c,e) == 1) || (tri(a,b,e) == 1 && dou(c,d) == 1) || (tri(a,c,d) == 1 && dou(b,e) == 1) || (tri(a,c,e) == 1 && dou(b,d) == 1) || (tri(a,d,e) == 1 && dou(b,c) == 1) || (tri(b,c,d) == 1 && dou(a,e) == 1) || (tri(b,c,e) == 1 && dou(a,d) == 1) || (tri(b,d,e) == 1 && dou(a,c) == 1) || (tri(c,d,e) == 1 && dou(a,b) == 1)){
		return 1;
	}
	else{
		return 0;
	}
}
int qua(int a, int b, int c, int d){
	if(tri(a,b,c) == 1 && tri(b,c,d) == 1){
		return 1;
	}
	else if(tri(a,b,c) == 1 || tri(a,c,d) == 1 || tri(b,c,d) == 1){
		return 2;
	}
	else{
		return 0;
	}
}
int tri(int a,int b, int c){
	if(dou(a,b) == 1 && dou(b,c) == 1){
		return 1;
	}
	else{
		return 0;
	}
}
int dou(int a, int b){
	int temp = a % 4;
	
	if(temp == 0){
		if(a-1 == b || a-2 == b || a-3 == b){
			return 1;
		}
		else{
			return 0;
		}
	}
	else if(temp == 1){
		if(a+1 == b || a+2 == b || a+3 == b){
			return 1;
		}
		else{
			return 0;
		}
	}
	else if(temp == 2){
		if(a-1 == b || a+1 == b || a+2 == b){
			return 1;
		}
		else{
			return 0;
		}
	}
	else if(temp == 3){
		if(a-1 == b || a-2 == b || a+1 == b){
			return 1;
		}
		else{
			return 0;
		}
	}
	

}
int roleDecision(){
	int who;
	if(player1[0] == 1){
		draw("","Do you want to be the landlord? 1. Yes 2. No");
		int yn;
		scanf("%d", &yn);	
		if(yn == 1){
			who = 1;
		}
		else{
			who = 0
		}
		if(decision(2) == 1){
			who = 2;
		}
		else if(decision(3) == 1){
			who = 3;
		}
		else if(decision(1) == 1){
			who = 1;
		}
		else{
			who = 0;
		}
		return who;
		 
	}
	else if(player2[0] == 1){
		
		if(decision(2) == 1){
			who = 2;
		}
		else{
			who = 0;
		}
		if(decision(3) == 1){
			who = 3;
		}
		else if(decision(1) == 1){
			who = 1;
		}
		else if(decision(2) == 1){
			who = 2;
		}
		else{
			who = 0;
		}
		return who;
	}	
	else if(player3[0] == 1){
		who = 3;
		if(decision(1) == 1){
			who = 1;
		}
		else if(decision(2) == 1){
			who = 2;
		}
		else if(decision(3) == 1){
			who = 3;
		}
		else{
			who = 0;
		}
		return who;
	}
	
} 
int decision(int a){
	if(a == 1){
		draw("","Do you want to grab the landlord? 1. Yes 2. No");
		int yn;
		scanf("%d", &yn);	
		if(yn == 1){
			return 1;
		}
		else{
			return 0;
		}
	}
	else if(a == 2){

	}
	else if(a == 3){

	}
}
int draw(char *ins, char *mess){
	int c1 = cardSize(player2);
	int c2 = cardSize(player3);
	int c = cardSize(player1);
	
			printf("________________________________________________________________________________________________________________________________________________\n\n");	
	
	printf("		Last 3 Round:\n");
	printf("		Last 2 Round:\n");
	printf("		Last 1 Round:\n");
	printf("		This   Round:\n");
	printf("________________________________________________________________________________________________________________________________________________\n\n");
	printf("Computer 1								Computer 2\nRole: %s								Role: %s\nCards left: %d 								Cards Left: %d\n",cr1,cr2,c1,c2);
	printf("________________________________________________________________________________________________________________________________________________\n\n");	
	printf("Game Instructor: %s\n", ins);
	printf("________________________________________________________________________________________________________________________________________________\n");
	
	printf("Card Left: %d     Role: %s\n",c,cr);
	int i;
	for(i = 0; i < cardSize(player1); i++){
		printf("|(%d)[",i+1);
		showCard(i,player1);
		printf("]");
	}
	printf("|(0)[SKIP]\n");
	printf("________________________________________________________________________________________________________________________________________________\nEnter Number for discarding, 0 means SKIP, H for Heart, D for Diamond, S for Spade, C for Club\n");
	printf("________________________________________________________________________________________________________________________________________________\n\n Game Message: &s\n", mess);
	return 0;
}

int sort(int list[]){
	int i,j,a;
		
	for(i = 0; i < cardSize(list); i++){
		for (j = i + 1; j < cardSize(list); j++)
		{
			if (list[i] > list[j])
			{
				a =  list[i];
				list[i] = list[j];
				list[j] = a;
			}
		} 
	}
	return 0;
}
int getCards(){
	int init;
	for(init = 0; init < 17; init++){
		int r1 = rand() % cardSize(card);
		player1[init] = card[r1];		
		rmCard(r1, card);
		int r2 = rand() % cardSize(card);
		player2[init] = card[r2];
		rmCard(r2, card);
		int r3 = rand() % cardSize(card);
		player3[init] = card[r3];
		rmCard(r3, card);

	}
	
	return 0;
}

int rmCard(int index, int list[]){
	int size = cardSize(list);
	if(index >= size){

	}
	else{
		int i;
		for(i = index; i < size; i++){
			list[i] = list[i+1];
			
			
		}
	}
	
	return 0;
}

int showCard(int index, int list[]){
	int tempc = list[index];
	if(tempc == 54){
		printf("BigJoker");
	}
	else if(tempc == 53){
		printf("SmallJoker");
	}
	else if(tempc % 4 == 1){
		printf("H");
		if(tempc <= 4){
			printf("3");
		}
		else if(tempc <= 8){
			printf("4");
		}
		else if(tempc <= 12){
			printf("5");
		}
		else if(tempc <= 16){
			printf("6");
		}
		else if(tempc <= 20){
			printf("7");
		}
		else if(tempc <= 24){
			printf("8");
		}
		else if(tempc <= 28){
			printf("9");
		}
		else if(tempc <= 32){
			printf("10");
		}
		else if(tempc <= 36){
			printf("J");
		}
		else if(tempc <= 40){
			printf("Q");
		}
		else if(tempc <= 44){
			printf("K");
		}
		else if(tempc <= 48){
			printf("A");
		}
		else if(tempc <= 52){
			printf("2");
		}
		
		
	}
	else if(tempc % 4 == 2){
		printf("D");
		if(tempc <= 4){
			printf("3");
		}
		else if(tempc <= 8){
			printf("4");
		}
		else if(tempc <= 12){
			printf("5");
		}
		else if(tempc <= 16){
			printf("6");
		}
		else if(tempc <= 20){
			printf("7");
		}
		else if(tempc <= 24){
			printf("8");
		}
		else if(tempc <= 28){
			printf("9");
		}
		else if(tempc <= 32){
			printf("10");
		}
		else if(tempc <= 36){
			printf("J");
		}
		else if(tempc <= 40){
			printf("Q");
		}
		else if(tempc <= 44){
			printf("K");
		}
		else if(tempc <= 48){
			printf("A");
		}
		else if(tempc <= 52){
			printf("2");
		}
	}
	else if(tempc % 4 == 3){
		printf("S");
		if(tempc <= 4){
			printf("3");
		}
		else if(tempc <= 8){
			printf("4");
		}
		else if(tempc <= 12){
			printf("5");
		}
		else if(tempc <= 16){
			printf("6");
		}
		else if(tempc <= 20){
			printf("7");
		}
		else if(tempc <= 24){
			printf("8");
		}
		else if(tempc <= 28){
			printf("9");
		}
		else if(tempc <= 32){
			printf("10");
		}
		else if(tempc <= 36){
			printf("J");
		}
		else if(tempc <= 40){
			printf("Q");
		}
		else if(tempc <= 44){
			printf("K");
		}
		else if(tempc <= 48){
			printf("A");
		}
		else if(tempc <= 52){
			printf("2");
		}
	}
	else if(tempc % 4 == 0){
		printf("C");
		if(tempc <= 4){
			printf("3");
		}
		else if(tempc <= 8){
			printf("4");
		}
		else if(tempc <= 12){
			printf("5");
		}
		else if(tempc <= 16){
			printf("6");
		}
		else if(tempc <= 20){
			printf("7");
		}
		else if(tempc <= 24){
			printf("8");
		}
		else if(tempc <= 28){
			printf("9");
		}
		else if(tempc <= 32){
			printf("10");
		}
		else if(tempc <= 36){
			printf("J");
		}
		else if(tempc <= 40){
			printf("Q");
		}
		else if(tempc <= 44){
			printf("K");
		}
		else if(tempc <= 48){
			printf("A");
		}
		else if(tempc <= 52){
			printf("2");
		}
	}
	
	return 0;
}
int cards(){
	int c, value;
	value = 1;
	for(c = 0; c < 54; c++){
		card[c] = value;
		value++;
	}
	return 0;
}
int cardSize(int list[]){
	
	int count = 0;	
	while(list[count] != 0){
		
		count++;
	}
	return count;
}
