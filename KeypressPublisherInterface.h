#ifndef __KEYPRESS_PUBLISHER_INTERFACE
#define __KEYPRESS_PUBLISHER_INTERFACE

/**
 * GNU GENERAL PUBLIC LICENSE
 * Version 3, 29 June 2007
 *
 * (C) 2020-2025, Bernd Porr <mail@bernporr.me.uk>
 * 
 **/

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <thread>

class KeypressPublisherInterface
{
public:
    
    struct CallbackInterface {
	virtual void hasEvent() = 0;
    };

    virtual void start() {
	if (uthread.joinable()) uthread.join();
	if (running) return;
	uthread = std::thread(&KeypressPublisherInterface::worker,this);
    }

    virtual void stop() {
	running = false;
	if (uthread.joinable()) uthread.join();
    }

    virtual ~KeypressPublisherInterface() {
	stop();
    }

    void registerEventCallback(CallbackInterface* cf) {
        callbackInterface = cf;
    }
    
private:
    CallbackInterface* callbackInterface = nullptr;
    bool running = false;
    std::thread uthread;
    void worker() {
	running = true;
	while (running) {
	    // we are blocking here
	    getchar();
	    // callback
	    if (callbackInterface)
		callbackInterface->hasEvent();
	}
    }
};

#endif
