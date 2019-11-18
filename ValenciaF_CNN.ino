#include "matriz_entrenamiento.h"
#define fil 120
#define col 5

float m_source[80][5];//datos validos 
float m_drain [120][5];//datos de desecho 
int f1=0; //recorrido de filas de matriz s
int c_source=0; //recorrido de matriz source - columna
int f_source=0; //recorrido de matriz source -fila
int f_drain=0;
int c_drain=0;
//float datos_prueba[5]= {5.8 , 2.7 ,4.1, 1,2};
int j=0; //moverse en filas
int i=0; //moverse en columnas
float potencia; //potencia de atributos
float raiz; //distancia de dos puntos
float dist_minima=3000; //almacenar la menor distancia 
float etiqueta;
int  centroides [3][4];

int respuesta;

void setup() {
 Serial.begin(9600);
 cnn(3,5,120);
}

void loop() {
    for(j=0;j<fil;j++){//moverse en filas
    for(i=0;i<col-1;i++){ //moverse en columnas
      for(;f_source<3;f_source++){
        for(;c_source<5;c_source++){
      potencia=potencia+pow(matriz[j][c_source]-centroides[f_source][c_source],2); //potencia entre columnas
    }
    raiz=sqrt(potencia); //raiz de potencias(distancia entre dos puntos)
    if(raiz<dist_minima){ //comparo a distancia menor
    dist_minima=raiz; //cambio de valor
    etiqueta=centroides[f_source][4]; //asigno prediccion de etiqueta
  }
  //end if
  potencia=0; //en cada lectura de fila, se encera la distancia
  c_source=0; //se encera la columna para lleer nuevamente 
  }
  f_source=0;  
  //si el algoritmo knn se realizo correctamente, se distribuyen los valores entre dos matrices s y d
  if(etiqueta==matriz[j][4]){
    //almacenamiento de datos d
    for(;f_drain<fil;f_drain++){
    for(;c_drain<col;c_drain++){
      m_drain[f_drain][c_drain]=matriz[j][c_drain];
    }
    c_drain=0;
    Serial.print(matriz[f_drain][c_drain]);
    Serial.print('=');
    Serial.print('D');
    delay(5500);
  }
  }
  else{
    //almacenamiento de datos s
    for(;f_source;f_source++){
    for(;c_source<fil;c_source++){
    m_source[f1][c_source]=matriz[j][c_drain];
    }
    c_drain=0;
    f1++;
     Serial.print(matriz[f1][c_source]);
    Serial.print('=');
    Serial.print('S');
    delay(5500);
  }
 }
}
}
}

void cnn (int etiquetas, int tam_col, int tam_fil){
  int i;
  int j;
  int l;
  float centroid=0;
/*  
 *   centroides -> promedio
 *                 promedio por columna y por etiqueta
 *                 almaceno vectores 
 *                 knn entre vectores y matriz de entrenamiento
 */

 float centroides [etiquetas][tam_col];
 for(i=0;i<etiquetas;i++){
   for(j=0;j<tam_col;j++){
     centroides[i][j]=0;
    }
  }

   for(l=0;l<etiquetas;l++){
     for(i=0;i<tam_col-1;i++){
       for(j=(40*l);j<40*(l+1);j++){
          centroid=centroid+matriz[j][i];
        }
          centroides[l][i]=centroid/40;
        //  m_source[etiquetas-1][tam_col]=centroides;//almacenar promedios en matriz de datos source
          Serial.print(centroides[l][i],4);
          Serial.print(',');
          centroid=0;
          j=0;
      }
      i=0;
          //Serial.println(' ');
   } 
   i=0;
   j=0;
   for(;j<3;j++){ //llenar etiquetas en vector, despues de encontrar puntos medios 
    matriz [j][4]=j+1;
   }
   j=0; 
}
