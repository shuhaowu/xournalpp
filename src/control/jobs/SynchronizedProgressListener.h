/*
 * Xournal++
 *
 * Adapter to call progress interface from outside the GTK Main thread
 *
 * @author Xournal++ Team
 * https://github.com/xournalpp/xournalpp
 *
 * @license GNU GPLv2 or later
 */

#pragma once

#include "ProgressListener.h"
#include <XournalType.h>

class SynchronizedProgressListener : public ProgressListener
{
public:
	SynchronizedProgressListener(ProgressListener* target);
	virtual ~SynchronizedProgressListener();

public:
	virtual void setMaximumState(int max);
	virtual void setCurrentState(int state);

private:
	static bool setMaxCallback(SynchronizedProgressListener* listener);
	static bool setCurrentCallback(SynchronizedProgressListener* listener);

public:
	XOJ_TYPE_ATTRIB;

	ProgressListener* target;

	int maxIdleId;
	int currentIdleId;

	int max;
	int current;
};
