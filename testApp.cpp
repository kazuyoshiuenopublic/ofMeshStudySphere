#include "testApp.h"

class Particle {
    
public:
    ofVec3f vel;
    ofVec3f pos;
    ofVec3f force;
};


ofMesh mesh;
Particle* particleArray[6][12];


//--------------------------------------------------------------
void testApp::setup()
{
    ofSetVerticalSync(true);
    ofSetFrameRate(60);
    ofEnableAlphaBlending();
    ofBackground(0,0,0);
    glEnable(GL_DEPTH_TEST);
    

    float r = 0;
    float deg = 0;
    float scale = 100;
    
    for (int i = 0; i < 3; i++)
    {
        r = cos( (i+1) * 25 * PI / 180 );
        deg = (i+1) * 25;
        
        cout << endl;
        cout << "r = " << r << endl;
        cout << "deg = " << deg << endl;
        
        float degForCircle = 0;
        for (int index = 0; index < 12; index ++)
        {
            degForCircle = index * 30;
            cout << "degForCircle = " << degForCircle << endl;
            Particle* p = new Particle();
            p->pos.x = cos(degForCircle*PI/180)*r;
            p->pos.y = sin(deg*PI/180);
            p->pos.z = sin(degForCircle*PI/180)*r;
            p->pos *= scale;
            cout << "x = " << p->pos.x << endl;
            cout << "y = " << p->pos.y << endl;
            cout << "z = " << p->pos.z << endl;
            
            Particle * rp = new Particle();
            rp->pos.x = cos(degForCircle*PI/180)*r;
            rp->pos.y = sin(deg*PI/180);
            rp->pos.z = sin(degForCircle*PI/180)*r;
            rp->pos *= (-1 * scale);

            particleArray[i][index] = p;
            particleArray[i+3][index] = rp;
        }
    }
        
    

    mesh.setMode(OF_PRIMITIVE_POINTS);
	for (int i = 0; i < 6; i++) {
        for (int index = 0; index < 12; index++)
        {
            mesh.addColor(ofFloatColor(1.0, 1.0, 1.0));            
        }
	}


    mesh.clearVertices();
    for (int i = 0; i < 6; i++)
    {
        for (int index = 0; index < 12; index++) {
            Particle *p = particleArray[i][index];
            mesh.addVertex(ofVec3f(p->pos.x, p->pos.y, p->pos.z));
        }
    }
    
    rotY = 0.0;
}



//--------------------------------------------------------------
void testApp::update(){
    rotY+=0.5;
}


//--------------------------------------------------------------
void testApp::draw(){
    

	ofPushMatrix();
    ofTranslate(ofGetWidth()/2, ofGetHeight()/2);

    glPointSize(1.0);
    glEnable(GL_POINT_SMOOTH);
    ofRotateY(rotY);
    mesh.drawVertices();

	ofPopMatrix();   
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}