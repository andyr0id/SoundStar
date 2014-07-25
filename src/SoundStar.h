#ifndef SOUNDSTAR_H
#define SOUNDSTAR_H

#include "ofMain.h"

class SoundStar
{
    public:
        int x;
        int y;
        int nBands;
        int nPoints = 32;
        int fps = 12;
        float smoothness = 0.5f;
        float randomness = 0.5f;
        int minRadius = 50;
        int radius = 800;

        SoundStar(string soundFile, int nBands);
        virtual ~SoundStar();

		void update();
		void draw();

    protected:
    private:
		ofSoundPlayer soundPlayer;
		int counter;
		float * spect;

		float getRandomOffset(float n = 1);
};

#endif // SOUNDSTAR_H
