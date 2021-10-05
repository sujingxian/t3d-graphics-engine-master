// =========================================================================================
// KXG363 - Advanced Games Programming
// =========================================================================================
//
// Author: Robert Ollington
//
// GameObject.cpp
//
// Simple task for drawing to and animating textures, used in tutorial 1 for practice implementing drawing routines

#include <math.h>
#include "Renderer.h"
#include "DrawTask.h"
#include "Logger.h"

namespace T3D 
{
	/*
	 * \param app Application root
	 * \param tex Texture to draw onto
	 *
	 * \note `tex` should be initialised, and registered with the renderer as both a loaded Texture and a 2D Overlay. This can be done using `new Texture(...)`, `loadTexture(...)`, and finally `add2DOverlay(...)`.
	 * \note If nothing is drawing on the screen, ensure the returned DrawTask object is added to the list of Tasks from the callsite using `addTask(...).
	 * \note If there is nothing on the screen still, check the visual studio console for error messages in case something is out of bounds.
	 *
	 */
	DrawTask::DrawTask(T3DApplication *app, Texture* tex) : Task(app)
	{
		drawArea = tex;

		// @BoundsCheck - requires using pushPixel
		// Reserve some space for the buffer, as its unlikely only few pixels will be plotted
		// const uint32_t pixelsToReserve = 512;
		// pixelPlotQueue.reserve(pixelsToReserve);

		init();
		logger::Log(priority::Info, output_stream::All, category::Task, "Initialised DrawTask");
	}

	/*
	 * \param 
	 * \note This isn't necessary. It could be inlined into the constructor.
	 */
	void DrawTask::init	(){		
		drawArea->clear(Colour(255,255,255,255));
		drawDDALine(100,100,200,200,Colour(0,0,0,255));
	}

	/*
	 * \param x1 Start x pixel coordinate 
	 * \param y1 Start y pixel coordinate
	 * \param x2 End x pixel coordinate 
	 * \param y2 End y pixel coordinate
	 * \param Colour of line
	 *
	 * \note Uses floating-point numbers as seen in the 2D graphics lecture.
	 * \note `pushPixel` is used to do large batches of *bounds-checked* pixel drawing, which you may prefer to your application crashing if you go outside the texture area.
	 */
	void DrawTask::drawPie(int cx, int cy, int r, float theta, Colour colour)
	{
		
		int prex = cx + r, prey = cy;
		float finalx = cx + r * cos(theta), finaly = cy + r * sin(theta);
		float slope1 = (cy - finaly) / (cx - finalx);
		float b = finaly - slope1 * finalx;
		float precision = pow(10, 0.0 - float(int(r / 100) + 1));

		if (precision >= 0.1)  precision = 0.01 ;

		for (float t = 0; t <= theta; t += precision) {
			int x = int(cx + r * cos(t));
			int y = int(cy + r * sin(t));

			if (x != prex && y != prey) {
				drawDDALine(x, y, int((y - b) / slope1), y, colour);
				drawArea->plotPixel(x, y, colour);
			}

		}
	}
	void DrawTask::drawDDALine(int x1, int y1, int x2, int y2,Colour c){

		float deltay = (y2 - y1);
		float deltax = (x2 - x1);
		float slope = deltay / deltax;
		if (deltax == 0) {
			if (y2 < y1) {
				for (int x = x1, y = y1; y >= y2; y--)
					pushPixel(x, y, c);
			}
			else {
				for (int x = x1, y = y1; y <= y2; y++)
					pushPixel(x, y, c);
			}
		}
		else if (deltay == 0) {
			if (x2 < x1) {
				for (int y = y1, x = x1; x >= x2; x--)
					pushPixel(x, y, c);
			}
			else {
				for (int y = y1, x = x1; x <= x2; x++)
					pushPixel(x, y, c);
			}
		}
		else {
			float y = y1;
			if (slope <= 1 && slope >= -1) {
				if (x2 > x1) {
					for (int x = x1; x <= x2; x++) {
						pushPixel(x, round(y), c);
						y = y + slope;
					}
				}
				else {
					for (int x = x1; x >= x2; x--) {
						pushPixel(x, round(y), c);
						y = y - slope;
					}
				}
			}
			else {
				if (x2 > x1) {
					for (int x = x1; x <= x2; x++) {
						pushPixel(x, round(y), c);
						y = y + slope;
					}
				}
				else {
					for (int x = x1; x >= x2; x--) {
						pushPixel(x, round(y), c);
						y = y - slope;
					}
				}
			}
		}
	

	}
		

	/*
	 * \param x1 Start x pixel coordinate 
	 * \param y1 Start y pixel coordinate
	 * \param x2 End x pixel coordinate 
	 * \param y2 End y pixel coordinate
	 * \param Colour of line
	 * 
	 * \note UNIMPLEMENTED! That's your job in the tutorials.
	 */
	void DrawTask::drawBresLine(int x1, int y1, int x2, int y2,Colour c)
	{ /* UNIMPLEMENTED */ }


	/*
	 * \param dt Change in time
	 *
	 * \note Make sure to clear the `drawArea` before you write to it.
	 */
	void DrawTask::update(float dt){
		drawArea->clear(Colour(255, 255, 255, 255));
		drawDDALine(100, 40, 20, 200, Colour(255,5,0,255));
		drawPie(200, 200, 80, 1.2, Colour(255, 200, 7, 255));

		// @BoundsCheck- requires using pushPixel
		// Plots pixels made to the drawArea this frame, clearing the pixel queue.
		flushPixelQueue();
		app->getRenderer()->reloadTexture(drawArea);
	}


	/*
	 * Provides a bounds-checked and more efficient way to draw onto a surface then `plotPixel()`.
	 * Diagnostic messages for out-of-bounds drawing are displayed onto the console, and into `T3D_Log.txt`.
	 * 
	 * \param x x pixel coordinate to draw onto
	 * \param y y pixel coordinate to draw onto
	 * \param Colour pixel colour
	 *
	 */
	void DrawTask::pushPixel(int x, int y, Colour colour)
	{
		pixelPlotQueue.push_back(Pixel { x, y, colour }); 
	}

	/*
	 * Provides a bounds-checked and more efficient way to draw onto a surface then `plotPixel()`.
	 * Diagnostic messages for out-of-bounds drawing are displayed onto the console, and into `T3D_Log.txt`.
	 *
	 *
	 * \note This should be called at the end of the `update` function.
	 */
	void DrawTask::flushPixelQueue()
	{
		const uint32_t MaxOutOfBoundsCount = 10u;
		uint32_t OutOfBoundsCount = 0u;
		for (auto &Pixel : pixelPlotQueue)
		{
			bool PixelWithinWidth  = (Pixel.x >= 0 && Pixel.x < drawArea->getWidth());
			bool PixelWithinHeight = (Pixel.y >= 0 && Pixel.y < drawArea->getHeight());
			bool PixelWithinBounds = (PixelWithinWidth && PixelWithinHeight);

			if (PixelWithinBounds)
			{
				drawArea->plotPixel(Pixel.x, Pixel.y, Pixel.colour);
			}
			else 
			{
				if (OutOfBoundsCount < MaxOutOfBoundsCount)
				{
					logger::Log(priority::Tracing,
							    output_stream::File,
							    category::Debug,
							   "Pixel out of bounds!\n"
							   "\tWidth  :: [0 <= X <= %4u :: %4d :: %5s]%s\n"
							   "\tHeight :: [0 <= Y <= %4u :: %4d :: %5s]%s\n"
							   ,
							   app->getRenderer()->WindowWidth,
							   Pixel.x, PixelWithinWidth  ? "OK" : "ERROR",
							   PixelWithinWidth  ?   ""  : " <<<\n",
							   app->getRenderer()->WindowHeight,
							   Pixel.y, PixelWithinHeight ? "OK" : "ERROR",
							   PixelWithinHeight  ?  ""  : " <<<\n");
				}
				OutOfBoundsCount++;
			}
		}

		if (OutOfBoundsCount >= MaxOutOfBoundsCount)
		{
			logger::Log(priority::Tracing,
						output_stream::File,
						category::Debug,
					   "... Repeats %u times ...\n"
					   ,
					   OutOfBoundsCount - MaxOutOfBoundsCount);
		}

		pixelPlotQueue.clear();
	}



}
