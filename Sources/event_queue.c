#include "event_queue.h"
#include "mc9s12xdp512.h"

//Event queues
EVENT_T event_queue[MAX_EVENTS];
EVENT_T priority_event_queue[MAX_PRIORITY_EVENTS] ;

//Event counters. Volatile variables! interrupts may change these values.
volatile static unsigned int  events_in_queue = 0;
volatile static unsigned int events_in_priority_queue = 0;

//In and out offsets
static unsigned int in_offset = 0;
static unsigned int out_offset = 0;
static unsigned int priority_in_offset = 0;
static unsigned int priority_out_offset = 0;

//How many events are there in the queue?
int get_total_events_in_queue(void) 
{
        return events_in_queue + events_in_priority_queue;
}

//Register new event
int register_event_in_queue(const EVENT_T *ev) 
{
        if(events_in_queue != MAX_EVENTS)
        {
                event_queue[in_offset++] = (*ev);
                if(in_offset == MAX_EVENTS)
                        in_offset = 0;
                events_in_queue++;
                return SUCCESS;
        }
        return FULL_EVENT_QUEUE;
}

//Register new priority event
int register_event_in_priority_queue(const EVENT_T *ev) 
{
        if(events_in_priority_queue != MAX_PRIORITY_EVENTS)
        {
                priority_event_queue[priority_in_offset++] = (*ev);
                if(priority_in_offset == MAX_PRIORITY_EVENTS)
                       priority_in_offset = 0;
                events_in_priority_queue++;
                return SUCCESS;
        }
        return FULL_EVENT_QUEUE;
}

//Return next event in event queue, or wait for one if event queue is empty
void wait_for_event(EVENT_T* ev) 
{
        while(!get_total_events_in_queue());
        
        if(events_in_priority_queue) 
        {
                (*ev) = priority_event_queue[priority_out_offset++];
                if(priority_out_offset == MAX_PRIORITY_EVENTS)
                             priority_out_offset = 0;
                events_in_priority_queue--;
        }
        else  //We know there are events here since we exited while
        {
                (*ev) = event_queue[out_offset++];
                if(out_offset == MAX_EVENTS)
                             out_offset = 0;
                events_in_queue--;
        }
}

//Remove all events from event queue
void flush_event_queue(void) 
{          
            _asm sei;     //No events while cleaning...
           events_in_priority_queue = events_in_queue = 0;
           in_offset = out_offset = 0;
           priority_in_offset = priority_out_offset = 0;
           _asm cli;      //Now, allow new events  
}