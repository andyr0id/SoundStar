#include "SoundStar.h"
#include "ofMain.h"

SoundStar::SoundStar(string soundFile, int nBands)
{
    this->nBands = nBands;
	soundPlayer.loadSound(soundFile, true);
    soundPlayer.play();
    float * val = ofSoundGetSpectrum(nBands);
    spect = new float[nBands];
    for (int i = 0; i < nBands; i++){
        spect[i] = val[i];
    }
}

SoundStar::~SoundStar()
{
    //dtor
}

void SoundStar::update(){
    //update spectrum
    float * val = ofSoundGetSpectrum(nBands);
    for (int i = 0; i < nBands; i++){
        spect[i] *= 0.96f;
        if (spect[i] < val[i]) spect[i] = val[i];
    }

    //update points
    bool newRandom = counter % fps == 0;



    counter++;
}

void SoundStar::draw(){
    ofSetColor(255,255,255);
    ofFill();

    ofVec2f center, x1, x2, realx1, realx2;
    center.set(x, y);

    int i = 0;
    float * pointVals = new float[nPoints];
    for (i = 0; i < nPoints; i++)
        pointVals[i] = 0.0f;

    float d_theta = (2 * PI) / (float)nPoints, theta = d_theta;

    for (i = 0; i < nBands; i++){
        if (spect[i] > pointVals[i % nPoints])
            pointVals[i % nPoints] = spect[i];
    }

    ofSetPolyMode(OF_POLY_WINDING_NONZERO);
    ofBeginShape();
    for (i = 0; i < nPoints; i++){
        x1.set(0, -minRadius - (pointVals[i] * (radius-minRadius)) + this->getRandomOffset());
        x1 = x1.getRotatedRad(theta);
        realx1 = x1 + center;
        ofVertex(realx1.x,realx1.y);
        x2 = x1 * smoothness;
        x2 = x2.getRotatedRad(d_theta * 0.5);
        realx2 = x2 + center;
        ofVertex(realx2.x,realx2.y);
        theta += d_theta;
    }
    ofEndShape();
}

float SoundStar::getRandomOffset(float n){
    return -(randomness*n) + (ofRandomf() * 2 * randomness * n);
}
