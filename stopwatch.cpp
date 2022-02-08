#include "stopwatch.h"

// Default constructor
Stopwatch::Stopwatch() :
    mRunning(false),
    mTotalTime(0),
    mTempTime(0)
{
}


void Stopwatch::start()
{
    mStartTime = QDateTime::currentDateTime();
    mRunning = true;
}


void Stopwatch::pause()
{
    mTotalTime += mTempTime;
    mRunning = false;
}


void Stopwatch::resume()
{
    mRunning = true;
}


void Stopwatch::reset()
{
    mTotalTime = 0;
    mRunning = false;
}


bool Stopwatch::isRunning()
{
    return mRunning;
}


void Stopwatch::setRunning(bool running)
{
    mRunning = running;
}


qint64 Stopwatch::getTime()
{
    mTempTime = mStartTime.msecsTo(QDateTime::currentDateTime());
    qint64 time = mTotalTime + mTempTime;
    return time;
}

