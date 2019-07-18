//Wakeup Operation
//When awaited event occurs -> another execution entity will call kwakeup, 
//which wakes up all the processes sleeping on the event value.
//If no process is sleeping on the event, kawakeup() has no effect => it does nothing

/*Algorithm of kwakeup(int event)*/

//Assume SLEEPing procs are in aglobal sleepList 
for each PROC *p in sleepList do{
	  if (p->event == event){        // if p is sleeping for the event 
	  	 delete p from sleepList;
	  	 p->status = READY;          // make p READY to run again
	  	 enqueue(&readyQueue, p);    // enter p into readyQueue
                 
	  }
}