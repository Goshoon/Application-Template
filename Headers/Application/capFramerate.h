#pragma once
#include "SDL.h"

#ifndef CAPFRAMERATE_H
#define CAPFRAMERATE_H

/* Lock 60 FPS */
void CapFrameRate(long* then, float* remainder);

#endif