//Initialisation de la bibliothèque pour permettre à l'Arduino
//d'interagir avec l'écran LCD (16 pixels sur 2 lignes)
#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);


//Déclaration des variables
int i = 0;
int temp = 0;   //valeur temporaire

//Initialisation des axes de coordonnees
int xread;
int xtemp;

int yread;
int ytemp;

int zread;
int ztemp;


// Initialisation des constantes pour les axes selon le montage
int xpin = A0;
int ypin = A1;
int zpin = A2;


//Fonction exécutée une seule fois lors de l'initialisation
void setup() {
  Serial.begin(9600);               //initialisation du port série, 9600 bits/seconde
  Serial.println("Operationnel);    //on vérifie que l'initialisation est lancée pour continuer

  lcd.begin(16, 2);                 //initialisation du nombre de pixels à l'écran, 16 pixels sur 2 lignes
  digitalWrite(13, HIGH);
  
  xtemp = analogRead(xpin);
  Serial.print(xtemp);

  ytemp = analogRead(ypin);
  Serial.print(ytemp);

  ztemp = analogRead(zpin);
  Serial.print(ztemp);

  digitalWrite(13, LOW);
}

//Fonction exécutée en boucle
void loop() {
  //i modulo 3 nous permet de savoir si on est dans le cas de l'axe x, y ou z
  //si on est dans le premier cas x, on affiche sa valeur
  //sur la première ligne à gauche de l'écran LCD
  if(i%3 == 0){
    xpin = temp;
    lcd.setCursor(0,0);
    lcd.print("x : ");
    lcd.print(temp);
  }

  //si on est dans le deuxième cas y, on affiche sa valeur
  //sur la première ligne au milieu de l'écran LCD
  if(i%3 == 1){
    ypin = temp;
    lcd.setCursor(8,0);
    lcd.print("y : ");
    lcd.print(temp);
  }
  
  //si on est dans le troisième cas z, on affiche sa valeur
  //sur la deuxième ligne à gauche de l'écran LCD
  if(i%3 == 2){
    zpin = temp;
    lcd.setCursor(0,1);
    lcd.print("z : ");
    lcd.print(temp);
  }
  i++;               //incrémentation
    
  delay(1000);       //délai de 1s avant le prochain affichage
  lcd.clear();       //on efface les valeurs affichées à l'écran
}
