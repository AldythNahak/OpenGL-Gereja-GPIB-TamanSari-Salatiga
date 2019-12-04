#include <windows.h>
#include <stdlib.h>
#include <GL/glut.h>
#include <math.h>
#include "imageloader.h"

void gambar(void);
void gereja(void);
void keyboard(unsigned char, int, int);
void ukuran(int, int);

int is_depth;
GLuint _textureIdkeramik;
GLuint _textureIdkeramik2;
GLuint _textureIdkeramik3;
GLuint _textureIddasar;
GLuint _textureIdgenteng;
GLuint _textureIdatap;
GLuint _textureIdpkanan;
GLuint _textureIdpkiri;
GLuint _textureIdLF1;
GLuint _textureIdLF2;
GLuint _textureIdLB1;
GLuint _textureIdLB2;
GLuint _textureIdRF1;
GLuint _textureIdRF2;
GLuint _textureIdRB1;
GLuint _textureIdRB2;
GLuint _textureIdlingkaran;
GLuint _textureIdkacadalam;
GLuint loadTexture(Image* image) {
	GLuint textureId;
	glGenTextures(1, &textureId);
	glBindTexture(GL_TEXTURE_2D, textureId);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, image->width, image->height, 0, GL_RGB, GL_UNSIGNED_BYTE, image->pixels);
	return textureId;
}

void gambar(void)
{
    glEnable(GL_DEPTH_TEST);
    is_depth = 1;
	glEnable(GL_COLOR_MATERIAL);
	glMatrixMode(GL_MODELVIEW);
	glEnable(GL_NORMALIZE);
    glEnable(GL_LINE_SMOOTH);
	glShadeModel(GL_SMOOTH);
	 glPointSize(7.0);
        glLineWidth(7.0f);

	Image* image = loadBMP("keramik.bmp");
	_textureIdkeramik = loadTexture(image);
		Image* image2 = loadBMP("keramik2.bmp");
	_textureIdkeramik2 = loadTexture(image2);
			Image* image3 = loadBMP("keramik3.bmp");
	_textureIdkeramik3 = loadTexture(image3);
			Image* image4 = loadBMP("dasar.bmp");
	_textureIddasar = loadTexture(image4);
				Image* image5 = loadBMP("genteng.bmp");
	_textureIdgenteng= loadTexture(image5);
				Image* image6 = loadBMP("atap.bmp");
	_textureIdatap = loadTexture(image6);
				Image* image7 = loadBMP("pintukanan.bmp");
	_textureIdpkanan = loadTexture(image7);
					Image* image8 = loadBMP("pintukiri.bmp");
	_textureIdpkiri = loadTexture(image8);
						Image* image9 = loadBMP("jendelaLB1.bmp");
	_textureIdLB1 = loadTexture(image9);
							Image* image10 = loadBMP("jendelaLB2.bmp");
	_textureIdLB2 = loadTexture(image10);
								Image* image11 = loadBMP("jendelaLF1.bmp");
	_textureIdLF1 = loadTexture(image11);
									Image* image12 = loadBMP("jendelaLF2.bmp");
	_textureIdLF2 = loadTexture(image12);
									Image* image13 = loadBMP("jendelaRB1.bmp");
	_textureIdRB1 = loadTexture(image13);
										Image* image14 = loadBMP("jendelaRB2.bmp");
	_textureIdRB2 = loadTexture(image14);
									Image* image15 = loadBMP("jendelaRF1.bmp");
	_textureIdRF1 = loadTexture(image15);
										Image* image16 = loadBMP("jendelaRF2.bmp");
	_textureIdRF2 = loadTexture(image16);
											Image* image17 = loadBMP("lingkaran.bmp");
	_textureIdlingkaran = loadTexture(image17);
												Image* image18 = loadBMP("kacadalam.bmp");
	_textureIdkacadalam = loadTexture(image18);
delete image;
delete image2;
delete image3;
delete image4;
delete image5;
delete image6;
delete image7;
delete image8;
delete image9;
delete image10;
delete image11;
delete image12;
delete image13;
delete image14;
delete image15;
delete image16;
delete image17;
delete image18;
}

void gedungkecil(float x, float y, float z, float panjang, float tinggi, float lebar,int warna) {//texture
	//Depan
	glBegin(GL_QUADS);
        glVertex3f(x, y, z);//kiri
	glVertex3f(x, y + tinggi-8, z);
	glVertex3f(x + 5, y + tinggi-8, z);
	glVertex3f(x + 5, y, z);
		glVertex3f(5, y, z);//kanan
	glVertex3f(5, y + tinggi-8, z);
	glVertex3f(panjang/2, y + tinggi-8, z);
	glVertex3f(panjang/2, y, z);
    glVertex3f(x, y+tinggi-8, z);//tengah
	glVertex3f(x, y + tinggi+5, z);
	glVertex3f(x +panjang, y + tinggi+5, z);
	glVertex3f(x + panjang, y+tinggi-8, z);
		//Kiri
	glVertex3f(x, y, z);
	glVertex3f(x, y + tinggi, z);
	glVertex3f(x, y + tinggi, z - lebar);
	glVertex3f(x, y, z - lebar);
		glVertex3f(x+3, y, z);//
	glVertex3f(x+3, y + tinggi, z);
	glVertex3f(x+3, y + tinggi, z - lebar-0.1);
	glVertex3f(x+3, y, z - lebar-0.1);
	//Kanan
	glVertex3f(x + panjang, y, z);
	glVertex3f(x + panjang, y + tinggi, z);
	glVertex3f(x + panjang, y + tinggi, z - lebar);
	glVertex3f(x + panjang, y, z - lebar);
		glVertex3f(x + panjang-3, y, z);//
	glVertex3f(x + panjang-3, y + tinggi, z);
	glVertex3f(x + panjang-3, y + tinggi, z - lebar-0.1);
	glVertex3f(x + panjang-3, y, z - lebar-0.1);
	glEnd();
//bawah
if(warna == 1){
    glBegin(GL_QUADS);
glColor3f(1.0,1.0,1.0);
	    glTexCoord2f(0.0f, 0.0f);
	glVertex3f(x, y, z);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(x + panjang, y, z);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(x + panjang, y, z - lebar);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(x, y, z - lebar);

		    glTexCoord2f(0.0f, 0.0f);//gedung BELAKANG lantai
            glVertex3f(x-2, y, -40.0);
            glTexCoord2f(1.0f, 0.0f);
            glVertex3f(x + panjang+1.5, y, -40.0);
            glTexCoord2f(1.0f, 1.0f);
            glVertex3f(x + panjang+1.5, y, -80.0);
            glTexCoord2f(0.0f, 1.0f);
            glVertex3f(x-2, y, -80.0);
            glEnd();
                     	    //les
    glBegin(GL_QUADS);
    glColor3f(0.0,0.0,0.0);
			glVertex3f(x+3+0.1, y, z);//kiri
	glVertex3f(x+3+0.1, y + 1, z);
	glVertex3f(x+3+0.1, y + 1, z - lebar-0.1);
	glVertex3f(x+3+0.1, y, z - lebar-0.1);
			glVertex3f(x + panjang-3, y, z);//kanan
	glVertex3f(x + panjang-3-0.1, y +1, z);
	glVertex3f(x + panjang-3-0.1, y +1 , z - lebar-0.1);
	glVertex3f(x + panjang-3-0.1, y, z - lebar-0.1);
	glEnd();
	glColor3f(1.0,1.0,1.0);
    }else if (warna == 0){
    glBegin(GL_QUADS);
     glVertex3f(x, y, z);
	glVertex3f(x + panjang, y, z);
	glVertex3f(x + panjang, y, z - lebar);
	glVertex3f(x, y, z - lebar);
	//gedung belakang
	glVertex3f(x-2, y, -40.0);//kiri
	glVertex3f(x-2, y + tinggi, -40.0);
	glVertex3f(x-2, y + tinggi, -45.0);
	glVertex3f(x-2, y,-45.0);
                                    glVertex3f(x-2, y, -55.0);//kiri
                                    glVertex3f(x-2, y + tinggi, -55.0);
                                    glVertex3f(x-2, y + tinggi, -80.0);
                                    glVertex3f(x-2, y, -80.0);
			glVertex3f(x + panjang+1.5, y, -40.0);//kanan
            glVertex3f(x + panjang+1.5, y + tinggi, -40.0);
            glVertex3f(x + panjang+1.5, y + tinggi, -80.0);
            glVertex3f(x + panjang+1.5, y, -80.0);
//BELAKANG
            glVertex3f(x-2, y, -80.0);
            glVertex3f(x + panjang+1.5, y, -80.0);
            glVertex3f(x + panjang+1.5, y+tinggi, -80.0);
            glVertex3f(x-2, y+tinggi, -80.0);

        //gedung depan//tembok depan
		  glColor3f(0.942f, 0.9f, 0.55f);
	glVertex3f(-12.0, 25.0, 15.0);
	glVertex3f(-3.0, 34.0, 15.0);
	glVertex3f(3.0, 34.0, 15.0);
	glVertex3f(12.0 , 25.0, 15.0);
glEnd();
    }
}

void gedungutama(float x, float y, float z, float panjang, float tinggi, float lebar,int warna) {//texture
	//Depan
	glBegin(GL_QUADS);
	glVertex3f(x, y, z);
	glVertex3f(x, y + tinggi, z);
	glVertex3f(x + ((panjang/2)-7+0.1), y + tinggi, z);
	glVertex3f(x + ((panjang/2)-7+0.1), y, z);
	//
    glVertex3f(6.9, y, z);
	glVertex3f(6.9, y + tinggi, z);
	glVertex3f(panjang/2, y + tinggi, z);
	glVertex3f(panjang/2, y, z);
	//
    glVertex3f(x + ((panjang/2)-7), tinggi+y, z);
	glVertex3f(x + ((panjang/2)-7), tinggi+y-10, z);
	glVertex3f(7,tinggi+y-10, z);
	glVertex3f(7, tinggi+y, z);
	//Belakang
	glVertex3f(x, y, z - lebar);
	glVertex3f(x, y + tinggi, z - lebar);
	glVertex3f(x +((panjang/2)-10), y + tinggi, z - lebar);
	glVertex3f(x + ((panjang/2)-10), y, z - lebar);
		//
    glVertex3f(0, y, z-lebar);
	glVertex3f(0, y + tinggi, z-lebar);
	glVertex3f(panjang/2, y + tinggi, z-lebar);
	glVertex3f(panjang/2, y, z-lebar);
	//
    glVertex3f(x + ((panjang/2)-10), tinggi+y, z-lebar);
	glVertex3f(x + ((panjang/2)-10), tinggi+y-12, z-lebar);
	glVertex3f(0,tinggi+y-12, z-lebar);
	glVertex3f(0, tinggi+y, z-lebar);
		//Kiri
	glVertex3f(x, y, z);
	glVertex3f(x, y + tinggi, z);
	glVertex3f(x, y + tinggi, z - lebar);
	glVertex3f(x, y, z - lebar);
	//Kanan
	glVertex3f(x + panjang, y, z);
	glVertex3f(x + panjang, y + tinggi, z);
	glVertex3f(x + panjang, y + tinggi, z - lebar);
	glVertex3f(x + panjang, y, z - lebar);
	glEnd();
//bawah
if(warna == 1){
    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 0.0f);
	glVertex3f(x, y, z);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(x + panjang, y, z);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(x + panjang, y, z - lebar);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(x, y, z - lebar);glEnd();
	//les
	    glBegin(GL_QUADS);
    glColor3f(0.0,0.0,0.0);
	//Depan
	glBegin(GL_QUADS);
	glVertex3f(x, y, z-0.1);//depan kiri
	glVertex3f(x, y + 1, z-0.1);
	glVertex3f(x + ((panjang/2)-7+0.1), y + 1, z-0.1);
	glVertex3f(x + ((panjang/2)-7+0.1), y, z-0.1);
    glVertex3f(6.9, y, z-0.1);//depan kanan
	glVertex3f(6.9, y + 1, z-0.1);
	glVertex3f(panjang/2, y + 1, z-0.1);
	glVertex3f(panjang/2, y, z-0.1);
	//belakang
    glVertex3f(x, y, z - lebar+0.1);//Belakang kiri
	glVertex3f(x, y + 1, z - lebar+0.1);
	glVertex3f(x +((panjang/2)-10), y + 1, z - lebar+0.1);
	glVertex3f(x + ((panjang/2)-10), y, z - lebar+0.1);
    glVertex3f(0, y, z-lebar+0.1);//Belakang kanan
	glVertex3f(0, y + 1, z-lebar+0.1);
	glVertex3f(panjang/2, y + 1, z-lebar+0.1);
	glVertex3f(panjang/2, y, z-lebar+0.1);
			//Kiri
	glVertex3f(x+0.1, y, z);
	glVertex3f(x+0.1, y + 1, z);
	glVertex3f(x+0.1, y + 1, z - lebar);
	glVertex3f(x+0.1, y, z - lebar);
	//Kanan
	glVertex3f(x + panjang-0.1, y, z);
	glVertex3f(x + panjang-0.1, y+ 1, z);
	glVertex3f(x + panjang-0.1, y+ 1, z - lebar);
	glVertex3f(x + panjang-0.1, y+1, z - lebar);
	glEnd();

glColor3f(0.9f, 0.9f, 0.9f);
    }else if (warna == 0){
    glBegin(GL_QUADS);
     glVertex3f(x, y, z);
	glVertex3f(x + panjang, y, z);
	glVertex3f(x + panjang, y, z - lebar);
	glVertex3f(x, y, z - lebar);glEnd();
    }
}

void balok(float x, float y, float z, float panjang, float tinggi, float lebar) {//texture
	//Depan
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(x, y, z);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(x, y + tinggi, z);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(x + panjang, y + tinggi, z);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(x + panjang, y, z);
	//Belakang
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(x, y, z - lebar);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(x, y + tinggi, z - lebar);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(x + panjang, y + tinggi, z - lebar);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(x + panjang, y, z - lebar);
		//Kiri
		glTexCoord2f(0.0f, 0.0f);
	glVertex3f(x, y, z);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(x, y + tinggi, z);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(x, y + tinggi, z - lebar);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(x, y, z - lebar);
	//Kanan
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(x + panjang, y, z);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(x + panjang, y + tinggi, z);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(x + panjang, y + tinggi, z - lebar);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(x + panjang, y, z - lebar);
	//Alas
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(x, y, z);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(x + panjang, y, z);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(x + panjang, y, z - lebar);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(x, y, z - lebar);
		//Atap
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(x, y+tinggi, z);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(x + panjang, y+tinggi, z);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(x + panjang, y+tinggi, z - lebar);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(x, y+tinggi, z - lebar);
	glEnd();
	}

void lingkaran(float xp, float yp, float r, float n,float z,float lebar,float pi){
    float a,x,y;
    glBegin(GL_POLYGON);
            a=pi/n;
        for (int i=0; i<n; i++){
            x = xp+r * cos(i*a);
             y = yp+r *1.57* sin(i*a);
            glVertex3f(x,y,z);
            glVertex3f(x,y,z+lebar);
        }
    glEnd();
}

void jendelaL(float yp, float zp, float r, float n,float x,float panjang,float pi){
    float a,z,y;
    if (pi> 3.14)
        r = r*1.57;
    glBegin(GL_POLYGON);
            a=pi/n;
        for (int i=0; i<n; i++){
            z = zp+r * cos(i*a);
            y = yp+r *sin(i*a);
            glVertex3f(x,y,z);
            glVertex3f(x+panjang,y,z);
        }
    glEnd();
//if (pi == 3.14)
//glLineWidth(5.0);
//     glBegin(GL_LINES);
//            a=3.14/n;
//        for (int i=0; i<n; i++){
//            z = zp+(r/2) * cos(i*a);
//            y = yp+(r/2) * sin(i*a);
//                glColor3f(0.0,0.0,0.0);
//            glVertex3f(x+0.3,y,z);
//            glVertex3f(x+panjang,y,z);
//        }
//    glEnd();
    }
void jendelaS(float x,float y,float z,float tinggi,float pi,float r){
    float a,xp,yp,n=180;
            a=pi/n;
               glBegin(GL_POLYGON);
        for (int i=0; i<n; i++){
            xp= x+r* cos(i*a);
            yp = y+7 * sin(i*a);
            glVertex3f(xp,yp+tinggi,z+0.1);
        }
    glEnd();
}
void jendela(float x, float y, float z, float panjang, float tinggi,float luar) {//TEXTURES
	//Depan
	    glColor3f(0.7f, 0.7f, 0.7f);
	glBegin(GL_QUADS);
	glVertex3f(x, y, z);
	glVertex3f(x, y + tinggi, z);
	glVertex3f(x + panjang, y + tinggi, z);
	glVertex3f(x + panjang, y, z);
        glEnd();
    if (y<=30.0){
	        glColor4f(0.0,0.0,0.8,0.6);///
            lingkaran(x+(panjang/2.0)+0.1, y+(tinggi+3.0), 0.5, 100.0, z+0.1, 0.0, 6.28);//luar
            lingkaran(x+2.2, y+tinggi+2.0 ,0.5, 100.0, z+0.1, 0.0, 6.28);
            lingkaran(x+(panjang/2.0)+0.5, y+tinggi+2.0 ,0.5, 100.0, z+0.1, 0.0, 6.28);
                lingkaran(x+(panjang/2.0)+0.1, y+(tinggi+3.0), 0.5, 100.0, z-0.1, 0.0, 6.28);//dalam
                lingkaran(x+2.2, y+tinggi+2.0 ,0.5, 100.0, z-0.1, 0.0, 6.28);
                lingkaran(x+(panjang/2.0)+0.5, y+tinggi+2.0 ,0.5, 100.0, z-0.1, 0.0, 6.28);
    }
if (luar==1) glColor3f(0.7f, 0.7f, 0.7f);
else 		glColor3f(0.4,0.5,0.6);
glBegin(GL_QUADS);
	glVertex3f(x, y+tinggi, z);
	glVertex3f(x+(panjang/2), y + tinggi+7, z);
	glVertex3f(x+(panjang/2), y + tinggi+7, z);
	glVertex3f(x + panjang, y + tinggi, z);
glEnd();
	glColor3f(0.6f, 0.6f, 0.6f);
glBegin(GL_LINE_LOOP);
	glVertex3f(x+0.2, y+tinggi, z+0.1);
	glVertex3f(x+(panjang/2), y + tinggi+6.5, z+0.1);
	glVertex3f(x+(panjang/2), y + tinggi+6.5, z+0.1);
	glVertex3f(x + panjang-0.2, y + tinggi, z+0.1);
glEnd();
if (y+tinggi > 30.0){
 while(34.0 <=y+tinggi){//geris-garis jendela lonceng
        float l;
        if(z <15) l= - 0.5;
        else l=0.5;
        glBegin(GL_QUADS);
		glVertex3f(x+0.5, y+tinggi-0.5, z);//motif
        glVertex3f(x+0.5, y+tinggi-1, z+l);
        glVertex3f(x + panjang-0.5, y+tinggi-1, z+l);
        glVertex3f(x + panjang-0.5, y+tinggi-0.5, z);
        glEnd();
        y--;
        y-=0.1;
        }return;}

if(luar == 1){
    glBegin(GL_QUADS);
		glVertex3f(x, y-1, z);//bawah
        glVertex3f(x, y - 2, z);
        glVertex3f(x + panjang, y -2, z);
        glVertex3f(x + panjang, y-1, z);
glEnd();
    //glColor3f(0.842f, 0.8f, 0.45f);
    glColor3f(0.7f, 0.7f, 0.7f);
        jendelaS(x+(panjang/2),y,z,tinggi,1.57,panjang/2);
        jendelaS(x+(panjang/2),y,z,tinggi,1.57,-(panjang/2));
        glColor3f(0.5,0.5,0.5);
        while(2.5 <=y+tinggi){
        float l;
        if(z <-20) l= - 0.5;
        else l=0.5;
        glBegin(GL_QUADS);
		glVertex3f(x+0.5, y+tinggi-0.5, z);//motif
        glVertex3f(x+0.5, y+tinggi-1, z+l);
        glVertex3f(x + panjang-0.5, y+tinggi-1, z+l);
        glVertex3f(x + panjang-0.5, y+tinggi-0.5, z);
        glEnd();
        y--;
        y-=0.1;
        }return;
}else{
    float i;
if(z<-20) i=0.1;
else i = - 0.1;
glColor3f(1, 1, 1);
        jendelaS(x+(panjang/2),y,z+i,tinggi,1.57,panjang/2);
        jendelaS(x+(panjang/2),y,z+i,tinggi,1.57,-(panjang/2));

        glBegin(GL_QUADS);
glColor3f(1,1,1);
    glTexCoord2f(0.0,0.0);//texture
	glVertex3f(x+0.5, y+0.5, z+i);
	glTexCoord2f(1.0,0.0);
	glVertex3f(x+0.5, y + tinggi-0.5, z+i);
	glTexCoord2f(1.0,1.0);
	glVertex3f(x + panjang-0.5, y + tinggi-0.5, z+i);
	glTexCoord2f(0.0,1.0);
	glVertex3f(x + panjang-0.5, y+0.5, z+i);
	glEnd();

	glColor3f(0.6f, 0.6f, 0.6f);
glBegin(GL_LINE_LOOP);
	glVertex3f(x+0.2, y+tinggi, z+i);
	glVertex3f(x+(panjang/2), y + tinggi+6.5, z+i);
	glVertex3f(x+(panjang/2), y + tinggi+6.5, z+i);
	glVertex3f(x + panjang-0.2, y + tinggi, z+i);
glEnd();
    }
}
void jendelasamping(float x, float y, float z, float lebar, float tinggi,float lonceng){
   glColor3f(0.9f, 0.9f, 0.9f);
//glColor3f(0.0f, 0.0f, 0.0f);
	glBegin(GL_QUADS);
	glVertex3f(x, y, z);
	glVertex3f(x, y + tinggi, z);
	glVertex3f(x , y + tinggi, z-lebar);
	glVertex3f(x, y, z-lebar);
    glEnd();
   glColor3f(0.7f, 0.7f, 0.7f);
glBegin(GL_QUADS);
	glVertex3f(x, y+tinggi, z);
	glVertex3f(x, y + tinggi+3, z-lebar/2);
	glVertex3f(x, y + tinggi+3, z-lebar/2);
	glVertex3f(x , y + tinggi, z-lebar);
glEnd();
float i,n;
if (x<0) i=-0.1;
else i=0.1;
while(y<=12){//jendela
                glBegin(GL_QUADS);
            glColor4f(0.8,0.8,0.8,0.3);
        glVertex3f(x+i, y+0.5, z-0.5);
        glVertex3f(x+i, y +4.8, z-0.5);
        glVertex3f(x+i , y + 4.8, z-(lebar-0.5));
        glVertex3f(x+i, y+0.5, z-(lebar-0.5));
                glVertex3f(-6.7, y+0.5, z-0.5);
                glVertex3f(-6.7, y +4.8, z-0.5);
                glVertex3f(-6.7, y + 4.8, z-(lebar-0.5));
                glVertex3f(-6.7, y+0.5, z-(lebar-0.5));
                                glVertex3f(6.7, y+0.5, z-0.5);
                                glVertex3f(6.7, y +4.8, z-0.5);
                                glVertex3f(6.7, y + 4.8, z-(lebar-0.5));
                                glVertex3f(6.7, y+0.5, z-(lebar-0.5));
        y++;
        y+=4;
        glEnd();
	}
glColor3f(0.7f, 0.7f, 0.7f);
//	jendelaL(y+3,z-lebar/2,0.2,100,-10.2,0.1,6.28);
	if (lonceng == 1){
        float l;
            while (y+tinggi>38.0){
              if(x<0) l =-0.5;
            else l=0.5;
                    glBegin(GL_QUADS);
                    glVertex3f(x, y+tinggi-0.5, z);
                    glVertex3f(x+l, y+tinggi-1, z);
                    glVertex3f(x + l, y+tinggi-1, z-2);
                    glVertex3f(x , y+tinggi-0.5, z-2);
                    glEnd();
        y--;
        y-=0.1;
        }} return;
}
void jendelabelakang(float x, float y, float z, float panjang, float tinggi){
while(y<=14){//jendela
                glBegin(GL_QUADS);
            glColor4f(0.8,0.8,0.8,0.3);
        glVertex3f(x+0.5, y+0.5, z+0.1);
        glVertex3f(x+0.5, y +4.8, z+0.1);
        glVertex3f(x+(panjang/2)-0.2 , y + 4.8, z+0.1);
        glVertex3f(x+(panjang/2)-0.2, y+0.5, z+0.1);
                glVertex3f(x+(panjang/2), y+0.5, z+0.1);
                glVertex3f(x+(panjang/2), y +4.8, z+0.1);
                glVertex3f(x+panjang-0.5 , y + 4.8, z+0.1);
                glVertex3f(x+panjang-0.5, y+0.5, z+0.1);
        glVertex3f(11.3, y+0.5, -55.5);
        glVertex3f(11.3, y +4.8, -55.5);
        glVertex3f(11.3 , y + 4.8, -57.8);
        glVertex3f(11.3, y+0.5, -57.8);
                    glVertex3f(11.3, y+0.5, -58.0);
                    glVertex3f(11.3, y +4.8, -58.0);
                    glVertex3f(11.3 , y + 4.8, -60.5);
                    glVertex3f(11.3, y+0.5, -60.5);
        y++;
        y+=4;
        glEnd();
	}
		    glColor3f(0.7f, 0.7f, 0.7f);
	glBegin(GL_QUADS);
	glVertex3f(x, y- tinggi-2, z);
	glVertex3f(x, y + tinggi/2-3, z);
	glVertex3f(x + panjang, y + tinggi/2-3, z);
	glVertex3f(x + panjang, y- tinggi-2, z);

	glVertex3f(x, y+tinggi/2-3, z);
	glVertex3f(x+(panjang/2), y +tinggi/2+1, z);
	glVertex3f(x+(panjang/2), y + tinggi/2+1, z);
	glVertex3f(x + panjang, y + tinggi/2-3, z);
	//kanan
		glVertex3f(11.4, y- tinggi-2, -55.0);
	glVertex3f(11.4, y + tinggi/2-3,- 55);
	glVertex3f(11.4, y + tinggi/2-3, -61);
	glVertex3f(11.4, y- tinggi-2, -61.0);

	glVertex3f(11.4, y+tinggi/2-3, -55.0);
	glVertex3f(11.4, y +tinggi/2+1, -58);
	glVertex3f(11.4, y + tinggi/2+1,- 58);
	glVertex3f(11.4, y + tinggi/2-3, -61.0);
        glEnd();
	return;
}
void kap(float yp, float zp, float r, float n,float x,float panjang){
    float a,z,y;
    glLineWidth(50.0);
    glBegin(GL_LINES);
            a=3.14/n;
        for (int i=0; i<n; i++){
            z = zp+r * cos(i*a);
            y = yp+(r/1.75) * sin(i*a);
            glVertex3f(x,y,z);
            glVertex3f(x+panjang,y,z);
        }
    glEnd();
}

void kapdpn(float xp, float yp, float r, float n,float z,float lebar,float pi){
    float a,x,y;
    glLineWidth(50.0);
    glBegin(GL_LINES);
            a=pi/n;
        for (int i=0; i<n;i++){
            x = xp+r * cos(i*a);
            y = yp+r *1.57* sin(i*a);
            glVertex3f(x,y,z);
            glVertex3f(x,y,z+lebar);
        }
    glEnd();
    glColor3f(0.4f, 0.5f, 0.6f);
    glBegin(GL_LINES);
            a=pi/100;
        for (int i=0; i<100;i++){
            x = 0.0+8.0* cos(i*a);
            y = 24.5+(8.0/1.5) * sin(i*a);
            glVertex3f(x,y,0.0);
            glVertex3f(x,y,14.5);
        }
    glEnd();
}

void les(float x, float y, float z, float panjang, float tinggi, float lebar) {
 while (-10 <= y){
    ///////////pendek//////////
    //depan
    glColor3f(0.45f, 0.45f, 0.45f);
    glBegin(GL_QUADS);
	glVertex3f(x, y, z);
	glVertex3f(x, y + tinggi, z);
	glVertex3f(x + panjang, y + tinggi, z);
	glVertex3f(x + panjang, y, z);
    //
	glVertex3f(-x, y, z);
	glVertex3f(-x, y + tinggi, z);
	glVertex3f(-x - panjang, y + tinggi, z);
	glVertex3f(-x - panjang, y, z);
    //belakang
	glVertex3f(x, y, z-40.2);
	glVertex3f(x, y + tinggi, z-40.2);
	glVertex3f(x + panjang, y + tinggi, z-40.2);
	glVertex3f(x + panjang, y, z-40.2);
    //
     glBegin(GL_QUADS);
	glVertex3f(-x, y, z-40.2);
	glVertex3f(-x, y + tinggi, z-40.2);
	glVertex3f(-x - panjang, y + tinggi, z-40.2);
	glVertex3f(-x - panjang, y, z-40.2);
    ///////////////panjang/////////////////
    glColor3f(0.5f, 0.5f, 0.5f);
	glVertex3f(x, y, z);
	glVertex3f(x, (y-4) + tinggi-1, z);
	glVertex3f(x + panjang+1.5, (y-4)+ tinggi-1, z);
	glVertex3f(x + panjang+1.5, y, z);
	//
	glVertex3f(-x, y, z);
	glVertex3f(-x, (y-4) + tinggi-1, z);
	glVertex3f(-x - panjang-1.5, (y-4)+ tinggi-1, z);
	glVertex3f(-x - panjang-1.5, y, z);
    //belakang
	glVertex3f(x, y, z-40.2);
	glVertex3f(x, (y-4) + tinggi-1, z-40.2);
	glVertex3f(x + panjang+1.5, (y-4)+ tinggi-1, z-40.2);
	glVertex3f(x + panjang+1.5, y, z-40.2);
	//
	glVertex3f(-x, y, z-40.2);
	glVertex3f(-x, (y-4) + tinggi-1, z-40.2);
	glVertex3f(-x - panjang-1.5, (y-4)+ tinggi-1, z-40.2);
	glVertex3f(-x - panjang-1.5, y, z-40.2);

    y--;
    y -= 4;
 }return;
}

void tangga(float x, float y, float z, float panjang, float tinggi, float lebar) {
	//Depan
	glBegin(GL_QUADS);
	glVertex3f(x, y, z);
	glVertex3f(x, y + tinggi, z);
	glVertex3f(x + panjang, y + tinggi, z);
	glVertex3f(x + panjang, y, z);
		//Kiri
	glVertex3f(x, y, z);
	glVertex3f(x, y + tinggi, z);
	glVertex3f(x, y + tinggi, z - lebar);
	glVertex3f(x, y, z - lebar);
//belakang
	glVertex3f(x, y, z - lebar);
	glVertex3f(x, y + tinggi, z - lebar);
	glVertex3f(x + panjang, y + tinggi, z - lebar);
	glVertex3f(x + panjang, y, z - lebar);
	//Alas
	glColor3f(0.9,0.9,1.0);
	glVertex3f(x, y, z);
	glVertex3f(x + panjang, y, z);
	glVertex3f(x + panjang, y, z - lebar);
	glVertex3f(x, y, z - lebar);
	glColor3f(0.63,0.32,0.18);
		glVertex3f(x, 3.3, -35.0);
        glVertex3f(x + panjang, 3.3, -35.0);
        glVertex3f(x + panjang, 3.3, -39.8);
        glVertex3f(x, 3.3, -39.8);
glEnd();
float c = -9.8,m=-30.0;
while (m>=-35.0){//anak tangga
balok(x+3,c,m,panjang-3,3,1);
balok(x+3,c+2,m-1,panjang-3,3,1);
	c++;
	m--;
	m-=1;
	c+=3;
}
while (m<=-30.0 && c <= 15){//anak tangga//c 3.3
balok(x+0.2,c+2,m+1,3,2,1);
balok(x+0.2,c,m,3,2,1);
	c++;
	m++;
	m+=1;
	c+=2;
}
glColor3f(0.9,0.9,0.9);
balok(x-0.1,-9.2,-35.5,2.9,12.0,3.8);
balok(x+0.5,-9.2,-34.9,1.9,12.0,3.8);
glBegin(GL_QUADS);
glVertex3f(x+2.8, -9.8, -35.0);
glVertex3f(x+2.8, 0, -35.0);
glVertex3f(x+2.8, -4, -25.0);
glVertex3f(x+2.8, -9.8, -25.0);
                                     glVertex3f(x+2.8, 9, -35.0);
                                        glVertex3f(x+2.8, 2, -35.0);
                                        glVertex3f(x+2.8, -3, -25.0);
                                        glVertex3f(x+2.8, 0, -25.0);
    glVertex3f(x-0.1, 9.5, -39.5);
   glVertex3f(x-0.1, 4.5, -39.5);
   glVertex3f(x-0.1, 4.5, -35.5);
    glVertex3f(x-0.1, 9.5, -35.5);
                                glVertex3f(x-0.1, 9.5, -34.5);
                                glVertex3f(x-0.1, 4.5, -34.5);
                                glVertex3f(x-0.1, 15, -24.5);
                                glVertex3f(x-0.1, 15, -29.5);
     glColor3f(0.9,0.9,0.9); //motif tangga
    glVertex3f(x-0.1, y+2, z-0.1);//atas
	glVertex3f(x-0.1, y + tinggi-0.6, z-0.1);
	glVertex3f(x-0.1, y + tinggi-0.6, z - lebar+0.2);
	glVertex3f(x-0.1, y+2, z - lebar+0.2);

glEnd();
while (z-lebar<= -10){
    glColor3f(0.5,0.5,0.5);
	glBegin(GL_LINE_LOOP);
glVertex3f(x-0.1, 20.0, z-lebar+1);
glVertex3f(x-0.1, 20.0, z-lebar/1.5);
glVertex3f(x-0.1, 20.5, z-lebar/1.5);
glVertex3f(x-0.1, 20.5, z-lebar/1.5-0.5);
glVertex3f(x-0.1, 17.5, z-lebar/1.5-0.5);
glVertex3f(x-0.1, 17.5, z-lebar/1.5);
glVertex3f(x-0.1, 18.0, z-lebar/1.5);
glVertex3f(x-0.1, 18.0, z-lebar+1);
glVertex3f(x-0.1, 17.5, z-lebar+1);
glVertex3f(x-0.1, 17.5, z-lebar+1.5);
glVertex3f(x-0.1, 20.5, z-lebar+1.5);
glVertex3f(x-0.1, 20.5, z-lebar+1);
glEnd();
z++;
z+=11.5;
}
	glBegin(GL_LINE_LOOP);
glVertex3f(x-0.1, 8.5, -39.2);
glVertex3f(x-0.1, 8.5,-35.5);
glVertex3f(x-0.1, 9, -35.5);
glVertex3f(x-0.1, 9, -36);
glVertex3f(x-0.1, 5.5, -36);
glVertex3f(x-0.1, 5.5, -35.5);
glVertex3f(x-0.1, 6, -35.5);
glVertex3f(x-0.1, 6, -39.2);//
glVertex3f(x-0.1, 5.5, -39.2);
glVertex3f(x-0.1, 5.5, -38.8);
glVertex3f(x-0.1, 9, -38.8);
glVertex3f(x-0.1, 9, -39.2);
glEnd();

glColor3f(0.9,0.9,1.0);
balok(x,-9.8,-35.0,3.0,13.0,4.8);
balok(x,4.0,-35.0,0.2,6.0,4.8);
glBegin(GL_QUADS);
	glVertex3f(x, 4.0, -35.0);
	glVertex3f(x, 10.0, -35.0);
	glVertex3f(x, 15.0, -30.0);
	glVertex3f(x, 15.0, -24.0);
        	glVertex3f(x, 4.0, -35.0);
            glVertex3f(x+3, 4.0, -35.0);
            glVertex3f(x+3, 15.0, -24.0);
            glVertex3f(x, 15.0, -24.0);
                    	glVertex3f(x+2.9, -9.8, -35.0);
                        glVertex3f(x+2.9, 10.0, -35.0);
                        glVertex3f(x+2.9, 0.0, -24.0);
                        glVertex3f(x+2.9, -9.8, -24.0);

glEnd();
return;
}

 void dpn(){
      float x = -12.0, y = 25.0, c = 1.0, panjang = 3.0 ;
    while (-2.0> x){
        balok(x, y, 16.0, panjang, 3.0, 2.0);//1
        x++;
        y++;
        x += 1;
        y += 1;
}
        while (9 > c ){
        balok(c, y-2, 16.0, panjang, 3.0, 2.0);//1
        c++;
        y--;
        c += 1;
        y -= 1;
  }
  balok(-1.5, 33.0, 16.0, panjang, 3.0, 2.0);
  return;
 }

 void lonceng(float x, float y, float z, float panjang, float tinggi, float lebar) {//texture
	glBegin(GL_QUADS);
	//Atap//depan
	    glTexCoord2f(0.0f, 0.0f);
	glVertex3f(x-2, y + tinggi-2, z-lebar +2);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(x, y + tinggi+2, z-lebar);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(x + panjang, y + tinggi+2, z-lebar);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(x+2+panjang, y + tinggi-2, z-lebar +2);
	//belakang
    glTexCoord2f(0.0f, 0.0f);
	glVertex3f(x-2, y + tinggi-2, z -2);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(x, y + tinggi+2, z);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(x + panjang, y + tinggi+2, z);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(x+2+panjang, y + tinggi-2, z-2);
		//kiri
    glTexCoord2f(0.0f, 0.0f);
	glVertex3f(x-2, y + tinggi-2, z -2);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(x, y + tinggi+2, z);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(x , y + tinggi+2, z-lebar);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(x-2, y + tinggi-2, z-lebar+2);
	//kanan
	    glTexCoord2f(0.0f, 0.0f);
	glVertex3f(x+panjang+2, y + tinggi-2, z -2);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(x+panjang, y + tinggi+2, z);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(x+panjang , y + tinggi+2, z-lebar);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(x+panjang+2, y + tinggi-2, z-lebar+2);

	////////segitiga////////

	//depan
    glTexCoord2f(0.0f, 0.0f);
	glVertex3f(x, y + tinggi+2, z-lebar);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(x+(panjang/2), y+tinggi+12, z-(lebar/2));
		glTexCoord2f(1.0f, 1.0f);
	glVertex3f(x+(panjang/2), y+tinggi+12, z-(lebar/2));
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(x + panjang, y + tinggi+2, z-lebar);
    //belakang
    glTexCoord2f(0.0f, 0.0f);
	glVertex3f(x, y + tinggi+2, z);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(x+(panjang/2), y+tinggi+12, z-(lebar/2));
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(x+(panjang/2), y+tinggi+12, z-(lebar/2));
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(x + panjang, y + tinggi+2, z);
//kiri
    glTexCoord2f(0.0f, 0.0f);
	glVertex3f(x, y + tinggi+2, z);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(x+(panjang/2), y+tinggi+12, z-(lebar/2));
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(x+(panjang/2), y+tinggi+12, z-(lebar/2));
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(x , y + tinggi+2, z-lebar);
	//kanan
    glTexCoord2f(0.0f, 0.0f);
	glVertex3f(x+panjang, y + tinggi+2, z);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(x+(panjang/2), y+tinggi+12, z-(lebar/2));
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(x+(panjang/2), y+tinggi+12, z-(lebar/2));
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(x+panjang , y + tinggi+2, z-lebar);


	glEnd();
 }
void lonceng2(float x, float y, float z, float panjang, float tinggi, float lebar){
		//Depan
		glBegin(GL_QUADS);
		glColor3f(0.4,0.5,0.6);
	glVertex3f(x, y, z);
	glVertex3f(x, y + tinggi, z);
	glVertex3f(x + panjang, y + tinggi, z);
	glVertex3f(x + panjang, y, z);
	//Belakang
	glVertex3f(x, y, z - lebar);
	glVertex3f(x, y + tinggi, z - lebar);
	glVertex3f(x + panjang, y + tinggi, z - lebar);
	glVertex3f(x + panjang, y, z - lebar);
		//Kiri
	glVertex3f(x, y, z);
	glVertex3f(x, y + tinggi, z);
	glVertex3f(x, y + tinggi, z - lebar);
	glVertex3f(x, y, z - lebar);
	//Kanan
	glVertex3f(x + panjang, y, z);
	glVertex3f(x + panjang, y + tinggi, z);
	glVertex3f(x + panjang, y + tinggi, z - lebar);
	glVertex3f(x + panjang, y, z - lebar);
	glEnd();
}
void atap2(float x, float y, float z, float panjang, float tinggi, float lebar) {//texture
	//Depan
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(x, y, z);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(x, y + tinggi, (z-(lebar/2)+1));
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(x + panjang, y + tinggi, (z-(lebar/2)+1));
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(x + panjang, y, z);
	//Belakang
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(x, y, z - lebar);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(x, y + tinggi, (z-(lebar/2)-1));
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(x + panjang, y + tinggi, (z-(lebar/2)-1));
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(x + panjang, y, z - lebar);
	///atap bwh////
	//atas
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-3.0, 34.0, 15.0);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-3.0, 34.0, 0.1);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(3.0, 34.0, 0.1);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(3.0 , 34.0, 15.0);
		//Kiri
		glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-12.0, 25.0, 15.0);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-3.0, 34.0, 15.0);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-3.0, 34.0, 0.1);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-12.0, 25.0, 0.1);
	//Kanan
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(12.0 , 25.0, 15.0);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(3.0, 34.0, 15.0);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(3.0, 34.0, 0.1);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(12.0, 25.0, 0.1);
	glEnd();
	    float a,zp,yp;
    glBegin(GL_POLYGON);
    	glColor3f(0.5,0.27,0.08);
            a=3.14/100;
        for (int i=0; i<100; i++){
            zp = z+1 * cos(i*a);
            yp = y+1.5* sin(i*a);
            glVertex3f(x,yp+tinggi,zp-(lebar/2));
            glVertex3f(x+panjang,yp+tinggi,zp-(lebar/2));
//            glVertex3f(x+panjang,yp+tinggi,zp-(lebar/2));
//            glVertex3f(x,yp+tinggi,zp-(lebar/2));
        }
    glEnd();
    //gedung belakang
    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 0.0f);//kanan
	glVertex3f(12.0 , 25.0, -40.0);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(6.5, 34.0, -40.0);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(6.5, 34.0, -75.0);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(12.0, 25.0, -81.0);
	    glTexCoord2f(0.0f, 0.0f);//kiri
	glVertex3f(-12.5 , 25.0, -40.0);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-6.0, 34.0, -40.0);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-6.0, 34.0, -75.0);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-12.5, 25.0, -81.0);
	    glTexCoord2f(0.0f, 0.0f);//belakang
	glVertex3f(12.0 , 25.0, -81.0);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(6.5, 34.0, -75.0);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-6.0, 34.0, -75.0);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-12.5, 25.0, -81.0);
	    glTexCoord2f(0.0f, 0.0f);//atas
	glVertex3f(6.5 , 34.0, -40.0);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-6.0, 34.0, -40.0);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-6.0, 34.0, -75.0);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(6.5, 34.0, -75.0);
//langit-langit
	glVertex3f(12.0 , 25.0, -40.0);
	glVertex3f(-12.5, 25.0, -40.0);
	glVertex3f(-12.5, 25.0, -81.0);
	glVertex3f(12.0, 25.0, -81.0);
	glEnd();
}

void atapkk(float x, float y, float z, float panjang, float tinggi, float lebar) {
	//atap GEREJA
		//Kiri
		glBegin(GL_QUADS);
	glVertex3f(x, y, z);
	glVertex3f(x, y + tinggi, z-(lebar/2)+1);
	glVertex3f(x, y + tinggi, z-(lebar/2)-1);
	glVertex3f(x, y, z - lebar);
	//Kanan
	glVertex3f(x + panjang, y, z);
	glVertex3f(x + panjang, y + tinggi, z-(lebar/2)+1);
	glVertex3f(x + panjang, y + tinggi, z-(lebar/2)-1);
	glVertex3f(x + panjang, y, z - lebar);
	glEnd();
}
void balokL(float p, float zp, float yp, float r){//penyangga kap depan
    balok(6.0, 13.0, 17.0, 1.25, 4.0, 2.0);//kanan
    balok(6.0, 14.5, 19.0, 1.25, 2.0, 2.0);
    balok(7.8, 13.0, 17.0, 1.25, 4.0, 2.0);
    balok(7.8, 14.5, 19.0, 1.25, 2.0, 2.0);
    balok(-7.25, 13.0, 17.0, 1.25, 4.0, 2.0);//kiri
    balok(-7.25, 14.5, 19.0, 1.25, 2.0, 2.0);
    balok(-9, 13.0, 17.0, 1.25, 4.0, 2.0);
    balok(-9, 14.5, 19.0, 1.25, 2.0, 2.0);
}

void pintu(float x, float y, float z, float panjang, float tinggi, float lebar){//texture
	if (x > 0){
            	glBegin(GL_QUADS);
		glTexCoord2f(0.0f, 0.0f);
	glVertex3f(x, y, z);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(x, y + tinggi, z);
        glTexCoord2f(1.0f, 1.0f);
    	glVertex3f(x+3, y + tinggi, z - lebar);
        glTexCoord2f(0.0f, 1.0f);
        glVertex3f(x+3, y, z - lebar);
        glEnd();
	}else if(x<0){
	                	glBegin(GL_QUADS);
		glTexCoord2f(0.0f, 0.0f);
	glVertex3f(x, y, z);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(x, y + tinggi, z);
        glTexCoord2f(1.0f, 1.0f);
    	glVertex3f(x-3, y + tinggi, z - lebar);
        glTexCoord2f(0.0f, 1.0f);
        glVertex3f(x-3, y, z - lebar);
    	glEnd();
	}
	//pintu belakang
	glColor3f(0.5,0.5,0.5);
	balok(-12.1,-10.0,-45.0,0.2,35.0,0.5);
	balok(-12.1,-10.0,-54.5,0.2,35.0,0.5);
	balok(-12.1,18.0,-45.0,0.2,0.5,9.5);
	balok(-12.1,24.0,-45.0,0.2,0.5,9.5);
}

void kursi(float x, float y, float z, float panjang, float tinggi, float lebar,float batas){
    while(x<=batas){
	glBegin(GL_QUADS);
	glColor3f(0.2,0.1,0.0); //178 34 34
	glVertex3f(x + panjang, y, z);//kanan
	glVertex3f(x + panjang, y + tinggi, z);
	glColor3f(0.3,0.1,0.0);
	glVertex3f(x + panjang, y + tinggi, z - lebar);
	glVertex3f(x + panjang, y, z - lebar);
	glColor3f(0.2,0.1,0.0);
	glVertex3f(x, y, z);//alas
	glVertex3f(x + panjang, y, z);
	glColor3f(0.3,0.1,0.0);
	glVertex3f(x + panjang, y, z - lebar);
	glVertex3f(x, y, z - lebar);
	glEnd();
	balok(x,-9.8,z,0.3,5.8,0.3);
	balok(x,-9.8,z-lebar+0.3,0.3,5.8,0.3);
	balok(x+panjang-0.3,-9.8,z,0.3,5.8,0.3);
	balok(x+panjang-0.3,-9.8,z-lebar+0.3,0.3,5.8,0.3);
	x++;
	x+= 4;
	glColor3f(0.2,0.1,0.0);
	balok(-2.0,-9.8,z,2,0.5,0.5);//kaki
	balok(-2.0,-9.8,z-lebar+0.3,2,0.5,0.5);
	glColor3f(0.3,0.1,0.0);
	balok(-1.8,-9.8,z,0.2,10,lebar+0.3);
	glColor3f(0.2,0.1,0.0);
	balok(-1.8,0.0,z,1.7,0.1,lebar+0.3);//
		glColor3f(0.3,0.1,0.0);
	balok(-1.8,-9.3,z,1.7,10.5,0.2);//kirikanan
	balok(-1.8,-9.3,z-lebar+0.3,1.7,10.5,0.2);

    }
    return;
}
void kursi2(float x, float y, float z, float panjang, float tinggi, float lebar,float sandaran){
    	if (z<-20.0) lebar=-lebar; x= x-3;
    	glBegin(GL_QUADS);
  glColor3f(0.3,0.1,0.0);
	glVertex3f(x, y, z);//dpn
	glVertex3f(x, y + tinggi, z);
	glColor3f(0.2,0.1,0.0);
	glVertex3f(x + panjang, y + tinggi, z);
	glVertex3f(x + panjang, y, z);
	glColor3f(0.2,0.1,0.0);
		glVertex3f(x, y, z);//alas
	glVertex3f(x + panjang, y, z);
glColor3f(0.2,0.1,0.0);
	glVertex3f(x + panjang, y, z - lebar);
	glVertex3f(x, y, z - lebar);
	glEnd();
	balok(x,-9.8,z,0.5,sandaran,lebar);
	balok(x+panjang,-9.8,z,0.5,sandaran,lebar);
	//
}

void gereja(void)
{
    if (is_depth)
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    else
    glClear(GL_COLOR_BUFFER_BIT);
   glEnable(GL_BLEND);
   glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    		glLightModeli(GL_LIGHT_MODEL_LOCAL_VIEWER,GL_TRUE);
		glEnable(GL_LIGHTING);
		glEnable(GL_LIGHT1);
		//set cahaya
		GLfloat qaAmbientLight[] = {0.7,0.7,0.7,1.0};
		GLfloat qaDiffuseLight[] = {0.7,0.7,0.7,1.0};
		GLfloat qaSpecularLight[] = {0.7,0.7,0.7,1.0};
		glLightfv(GL_LIGHT1, GL_AMBIENT,qaAmbientLight);
		glLightfv(GL_LIGHT1,GL_DIFFUSE,qaDiffuseLight);
		glLightfv(GL_LIGHT1,GL_SPECULAR,qaSpecularLight);
		//posisi cahaya
		//GLfloat cahaya[] = {25,50,100,1};
		GLfloat cahaya[] = {50,50,100,1};
		glLightfv(GL_LIGHT1,GL_POSITION,cahaya);
	glEnable(GL_COLOR_MATERIAL);
	glShadeModel(GL_SMOOTH);
    glMatrixMode(GL_MODELVIEW);
    ///////////////////////balok segala sisi/////////////////////////////////////
     glColor3f(0.5f, 0.5f, 0.5f);
    balok(-11.0, -10.0, 16.0, 2.0, 40.5, 2.0);//dpn kiri
    balok(9.0, -10.0, 16.0, 2.0, 40.5, 2.0);//dpn kanan
    balok(-11.0, -10.0, 0.5, 0.5, 35.0, 0.5);//dpn2 kiri
    balok(10.0, -10.0, 1.0, 0.5, 35.0, 0.5);//dpn2 kanan
    les(-40.0, 33.0, 0.1, 2.0, 2.0, 0.1);
        glColor3f(0.6f, 0.6f, 0.6f);
    balok(-41.0, 33.0, 1.0, 82.0, 2.0, 5.0);//atas
    balok(-41.0, 33.0, -36.0, 82.0, 2.0, 5.0);//atas
    ////////////////////////Bangunan Gereja///////////////////////////////////////
    glColor3f(1,1,1);
   atapkk(-39.9,35.0,0.9,79.8,18.0,42.0);
    glColor3f(0.942f, 0.9f, 0.55f);
      atapkk(-40.0,35.0,0.9,80.0,18.0,42.0);
    gedungkecil(-10.0, -10.0, 15.0, 20.0, 35.0, 15.0,0);//tembok luar
    gedungutama(-40.0, -10.0, 0.0, 80.0, 45.0, 40.0,0);//tembok luar
    glColor3f(0.5f, 0.6f, 0.7f);
    kap(33.2,-20.0,18.0,360.0,-39.8,79.0);//kap setengah lingkaran
    glColor4f(0.0f, 0.0f, 1.0f,0.7);
    jendelaL(37,-20.0,4.0,180.0,39.8,0.1,3.14);//jendela setengah lingkaran
    jendelaL(37,-20.0,4.0,180.0,40,0.1,3.14);
    jendelaL(37,-20.0,4.0,180.0,-40.1,0.1,3.14);
    jendelaL(37,-20.0,4.0,180.0,-39.8,0.1,3.14);
   ////////jendela/////////////
    jendela(-17.0,2.0,0.1,5.0,18.0,1.0);//depan
    jendela(-23.0,2.0,0.1,5.0,18.0,1.0);
     jendela(11.5,2.0,0.1,5.0,18.0,1.0);
    jendela(17.5,2.0,0.1,5.0,18.0,1.0);
        jendela(-17.0,2.0,-40.2,5.0,18.0,1.0);//belakang
        jendela(-23.0,2.0,-40.2,5.0,18.0,1.0);
        jendela(11.5,2.0,-40.2,5.0,18.0,1.0);
        jendela(17.5,2.0,-40.2,5.0,18.0,1.0);
        jendela(-3,0.0,-80.2,6.0,14.0,1.0);//jendela gedung belakang
//         jendela(-3,0.0,-79.9,6.0,14.0,0.0);
        jendelabelakang(-3.0,0.0,-79.9,6.0,14.0);
 glColor3f(0.9f, 0.9f, 0.9f);
        jendelasamping(-10.1,2.0,10.0,3.0,15.0,0);//kiri luar
        jendelasamping(-10.1,2.0,6.0,3.0,15.0,0);
        jendelasamping(10.1,2.0,10.0,3.0,15.0,0);//kanan luar
        jendelasamping(10.1,2.0,6.0,3.0,15.0,0);
                    jendelasamping(-6.8,2.0,10.0,3.0,15.0,0);//kiri dalam
                    jendelasamping(-6.8,2.0,6.0,3.0,15.0,0);
                    jendelasamping(6.8,2.0,10.0,3.0,15.0,0);//kanan dalam
                    jendelasamping(6.8,2.0,6.0,3.0,15.0,0);
            jendelasamping(-3.1,37.0,14.5,2.0,10.0,1);//kiri lonceng
            jendelasamping(-3.1,37.0,11.5,2.0,10.0,1);
            jendelasamping(3.1,37.0,14.5,2.0,10.0,1);//kanan lonceng
            jendelasamping(3.1,37.0,11.5,2.0,10.0,1);
        jendela(-2.5,37.0,15.1,2.0,7.0,1.0);//lonceng//depan
        jendela(0.5,37.0,15.1,2.0,7.0,1.0);
        jendela(-2.5,37.0,8.9,2.0,7.0,1.0);//belakang
        jendela(0.5,37.0,8.9,2.0,7.0,1.0);
 //////////////////Dalam Gereja///////////////////////////////
 glColor3f(0.5,0.53,0.6);
 tangga(30.0,15.0,-0.2,9.8,7.0,39.7);
 kursi(2.0,-4.0,-2.0,2.0,5.0,7.0,39.0);//kursi jemaat
 kursi(2.0,-4.0,-14.0,2.0,5.0,7.0,39.0);
 kursi(2.0,-4.0,-26.0,2.0,5.0,7.0,30.0);
 kursi2(-31.0,-4.0,-0.5,10.0,8.0,3.0,7.8);//kursi majelis kiri
 kursi2(-19.0,-4.0,-0.5,10.0,8.0,3.0,7.8);
  kursi2(-31.0,-4.0,-5.5,10.0,5.0,3.0,7.8);
 kursi2(-19.0,-4.0,-5.5,10.0,5.0,3.0,7.8);
   kursi2(-31.0,-4.0,-39.8,10.0,5.0,3.0,7.8);//kursi majelis kanan
 kursi2(-19.0,-4.0,-39.8,10.0,5.0,3.0,7.8);
   kursi2(-31.0,-4.0,-34.0,10.0,5.0,3.0,7.8);//kursi majelis kanan
 kursi2(-19.0,-4.0,-34.0,10.0,5.0,3.0,7.8);
 //mimbar//
  glColor3f(0.1,0.05,0.02);
 balok(-31.0,-9.8,-16.0,5.0,1.0,8.0);
 balok(-29.0,-7.8,-17.2,3.0,1.0,5.5);
balok(-28.5,-7.8,-16.0,2.5,12.0,0.5);//
balok(-28.5,-7.8,-23.5,2.5,12.0,0.5);
balok(-26.5,-7.8,-16.0,0.5,12.0,8.0);
  balok(-29.0,-8.8,-16.0,3.0,1.0,8.0);
  	//Salib
    glColor3f(1,1,1);//lonceng
	balok(-2.0,45.0,16.5,4.0,1.8,1.0);
	balok(-0.7,37.0,16.5,1.4,12.0,1.0);
	glColor4f(1.0,0.0,0.0,0.5);
    balok(-1.5,45.2,16.6,3.0,1.1,0.5);
	balok(-0.5,37.5,16.6,1.0,11.0,0.5);
	glColor3f(0,0,0);//dalam gereja
		balok(-39.8,12.5,-19.99,0.1,3.0,0.1);
      balok(-39.8,15.0,-19.5,0.1,0.1,1.0);
//////////////daerah pintu,menara,dll////////////////
lonceng2(-3.0,32.0,9.0,6.0,22.0,-5.9);
glColor3f(0.5f, 0.5f, 0.5f);
     glColor3f(0.647f, 0.165f, 0.165f);
   kapdpn(0.0,18.0,7.0,100.0,15.1,6.9,3.14);//kap pintu
    glColor3f(0.8,0.8,0.8);
    kapdpn(0.0,17.8,7.0,100.0,15.1,6.9,3.14);
    glColor3f(0.5f, 0.5f, 0.5f);
    balok(9.0, 25.0, 16.0, 3.0, 3.0, 16.0);
    balok(-12.0, 25.0, 16.0, 3.0, 3.0, 16.0);
    dpn();//zigzag
    balokL(6.0,16.0,17.0,4.0);
    glColor3f(0.55f, 0.55f, 0.55f);
           balok(6.0, 16.0, 22.0, 3.0, 3.0, 7.0);//dibwh stgh lingkaran
            balok(-9.0, 16.0, 22.0, 3.0, 3.0, 7.0);
    kapdpn(0.0,17.9,7.0,100.0,22.0,0.2,3.14);
    kapdpn(0.0,18.0,5.5,100.0,15.5,0.4,3.14);//sekeliling jendela
    kapdpn(0.0,18.0,6.0,100.0,15.5,0.4,3.14);//sekeliling jendela
    glBegin(GL_LINES);//garis samping pintu
    glVertex3f(5.5,-9.8,15.5);
    glVertex3f(5.5,17.5,15.5);
        glVertex3f(-5.5,-9.8,15.5);
    glVertex3f(-5.5,17.5,15.5);
    glEnd();
    balok(6.0, 16.0, 22.0, 3.0, 3.0, 7.0);//dibwh stgh lingkaran
    balok(-9.0, 16.0, 22.0, 3.0, 3.0, 7.0);
    glColor4f(0.7,0.7,0.7,0.5);
    lingkaran(0.0,18.0,5.0,100.0,15.1,0.0,3.14);//jendela
    lingkaran(0.0,18.0,5.0,100.0,14.8,0.0,3.14);//jendela
//pintu
    	glColor3f(0.5,0.27,0.08);
    	balok(-5.0,-10.0,15.5,0.5,27.0,1.0);
    	balok(4.5,-10.0,15.5,0.5,27.0,1.0);
    	balok(-5.0,16.0,15.5,10.0,1.0,1.0);
    	//glColor3f(1.0,1.0,1.0);
    	glColor3f(0.5,0.27,0.08);
    	        glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, _textureIdpkanan);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    	pintu(4.0,-10.0,15.0,3.0,26.0,5.0);glColor3f(0.5,0.27,0.08);
    	        glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, _textureIdpkiri);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
     	pintu(-4.0,-10.0,15.0,-3.0,26.0,5.0);

     glColor3f(0.6,0.6,0.6);
     glBegin(GL_QUADS);
    glVertex3f(-12.0, -9.9, -45.5);//belakang
	glVertex3f(-12.0, 17.8, -45.5);
	glVertex3f(-12.0, 17.8, -54.5);
	glVertex3f(-12.0, -9.9, -54.5);
	glEnd();
    //////////////////gedung gereja + texture///////////////////////////////
    	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, _textureIdkeramik2);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glColor3f(1.0f, 1.0f, 1.0f);
    gedungkecil(-9.9, -9.9, 14.9, 19.8, 35.1, 14.9,1);//tembok dalam

glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, _textureIdkeramik);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    gedungutama(-39.9, -9.9, -0.1, 79.8, 45.1, 39.8,1);//tembok dalam

    glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, _textureIdkeramik3);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    balok(-10.0,-10.1,24.0,20.0,0.1,9.0);//keramik luar

    glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, _textureIddasar);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    balok(-50.0,-10.5,70.0,100.0,0.1,200.0);//dasar

        glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, _textureIdgenteng);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    atap2(-40.0,35.0,0.9,80.0,18.0,42.0);//atap gedung gereja

        glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, _textureIdatap);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    lonceng(-3.0,32.0,9.0,6.0,22.0,-5.9);//atap menara

 //JENDELA   //texture start
    	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, _textureIdLF1);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
            jendela(-17.0,2.0,-0.2,5.0,18.0,0.0);//dalam depan//jendelaLF1
                	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, _textureIdLF2);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
            jendela(-23.0,2.0,-0.2,5.0,18.0,0.0);//jendelaLF2
                	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, _textureIdLB2);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
            jendela(11.5,2.0,-0.2,5.0,18.0,0.0);//jendelaLB2
                	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, _textureIdLB1);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
            jendela(17.5,2.0,-0.2,5.0,18.0,0.0);//jendelaLB1
                	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, _textureIdRF1);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
                jendela(-17.0,2.0,-39.8,5.0,18.0,0.0);//dalam belakang//jendelaRF1
                    	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, _textureIdRF2);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
                jendela(-23.0,2.0,-39.8,5.0,18.0,0.0);//jendelaRF2
                    	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, _textureIdRB2);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
                jendela(11.5,2.0,-39.8,5.0,18.0,0.0);//jendelaRB2
                    	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, _textureIdRB1);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
                jendela(17.5,2.0,-39.8,5.0,18.0,0.0);//jendelaRB1
 //textureEND
                	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, _textureIdlingkaran);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-3, 18, 15.3);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-3, 24.8, 15.3);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(3, 24.8, 15.3);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(3 , 18, 15.3);
		glTexCoord2f(0.0f, 0.0f);/////////
	glVertex3f(-3, 18, 14.7);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-3, 24.8, 14.7);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(3, 24.8, 14.7);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(3 , 18, 14.7);
	glEnd();
                	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, _textureIdkacadalam);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glBegin(GL_QUADS);
		glColor4f(1,1,1,0.7);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-7, 15, 0.0);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-7, 25.0, 0.0);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(7, 25.0, 0);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(7 , 15, 0.0);
	glEnd();
	glDisable(GL_TEXTURE_2D);
    glutSwapBuffers();
}

void scale(int w, int h)
{
    if (h == 0) h= 1;

    glMatrixMode(GL_PROJECTION);
      glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluPerspective(50.0, w/ h, 5.0, 500.0);
    glTranslatef(0.0, -10.0, -150.0);
}

void keyboard(int key, int x, int y)
{
    switch (key)
    {
	case GLUT_KEY_UP:
		glTranslatef(0.0, 0.0, 3.0);
		;break;
	case GLUT_KEY_RIGHT:
        glTranslatef(3.0, 0.0, 0.0);
        break;
	case GLUT_KEY_DOWN:
        glTranslatef(0.0, 0.0, -3.0);
        break;
	case GLUT_KEY_LEFT:
        glTranslatef(-3.0, 0.0, 0.0);
        break;
	}
	gereja();
}

void keyboard2(unsigned char key,int x,int y)
{
	switch (key)
	{
    case 'i':case 'I':
    glMatrixMode(GL_PROJECTION);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluPerspective(50.0, 1280/720, 5.0, 500.0);
    glTranslatef(0.0, -10.0, -10.0);
        break;
    case '0':
    glMatrixMode(GL_PROJECTION);
      glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluPerspective(50.0, 1280/720, 5.0, 500.0);
    glTranslatef(0.0, -10.0, -150.0);
        break;
	case '7':
        glTranslatef(0.0,3.0,0.0);
        break;
	case '9':
        glTranslatef(0.0,-3.0, 0.0);
        break;
    case '2':
        glRotatef(2.0,1.0,0.0,0.0);
        break;
    case '8':
        glRotatef(-2.0,1.0,0.0,0.0);
        break;
    case '6':
        glRotatef(2.0,0.0,1.0,0.0);
        break;
    case '4':
        glRotatef(-2.0,0.0,1.0,0.0);
        break;
    case '1':
        glRotatef(2.0,0.0,0.0,4.0);
        break;
    case '3':
        glRotatef(-2.0,0.0,0.0,1.0);
        break;
    case '5':
        if (is_depth)
        {
            is_depth = 0;
            glDisable(GL_DEPTH_TEST);
        }
        else
        {
            is_depth = 1;
            glEnable(GL_DEPTH_TEST);
        }
    }
    gereja();
}

int main (int argc, char **argv)
{
	glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(1366,768);
    glutInitWindowPosition(40,0);
    glutCreateWindow("Gereja");
    gambar();
    glutReshapeFunc(scale);
	glutDisplayFunc(gereja);
	glutSpecialFunc(keyboard);
	glutKeyboardFunc(keyboard2);
    glutMainLoop();
    return 0;
}
