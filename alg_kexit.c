//Process terminate or die
//Process terminate in two possible ways 
//Normal termination: the process calls exit(value)->_exit(value)=>system call to execute kexit in the OS kernel
//Abnormal termination->process terminate abnormally=>due to a signal 

/*ALGORITHM OF kexit(int exitValue)
1. Erase process user-mode context
2. Dispose of children processes, if any
3. Record exitValue in PROC.exitcode for parent to get 
4. Become a ZOMBIE
5. Wakeup parent adn, if needed, also the INIT process P1