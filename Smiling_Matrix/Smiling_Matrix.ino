 // Broches de la matrice LED
#define ROW_1 2
#define ROW_2 3
#define ROW_3 4
#define ROW_4 5
#define ROW_5 6
#define ROW_6 7
#define ROW_7 8
#define ROW_8 9

#define COL_1 10
#define COL_2 11
#define COL_3 12
#define COL_4 13
#define COL_5 A0
#define COL_6 A1
#define COL_7 A2
#define COL_8 A3

const byte rows[8] = {ROW_1, ROW_2, ROW_3, ROW_4, ROW_5, ROW_6, ROW_7, ROW_8};
const byte cols[8] = {COL_1, COL_2, COL_3, COL_4, COL_5, COL_6, COL_7, COL_8};

// Coordonnées des LEDs à allumer
const byte ledPoints[8][2] = {
  {2, 2}, {5, 2}, {6, 5}, {5, 6},
  {1, 5}, {2, 6}, {3, 6}, {4, 6}
};

void setup() {
  Serial.begin(9600);
  Serial.println("Allumage de 8 LEDs pendant 6 secondes");

  for (int i = 0; i < 8; i++) {
    pinMode(rows[i], OUTPUT);
    pinMode(cols[i], OUTPUT);
  }
}

void loop() {
  unsigned long start = millis();
  while (millis() - start < 6000) {
    for (int i = 0; i < 8; i++) {
      clearMatrix();  // Efface avant chaque point pour éviter les superpositions
      lightUp(ledPoints[i][0], ledPoints[i][1]);
      delay(3);  // Très court pour simuler l'allumage simultané (persistence rétinienne)
    }
  }

  clearMatrix();  // Éteindre tout après les 6 secondes
  delay(2000);    // Petite pause avant de recommencer
}

// Allume une LED spécifique (colonne x, ligne y)
void lightUp(int x, int y) {
  digitalWrite(rows[y], LOW);   // Active ligne
  digitalWrite(cols[x], HIGH); // Active colonne
}

// Éteint toute la matrice
void clearMatrix() {
  for (int i = 0; i < 8; i++) {
    digitalWrite(rows[i], HIGH);
    digitalWrite(cols[i], LOW);
  }
} 