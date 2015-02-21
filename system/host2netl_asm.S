/*------------------------------------------------------------------------
 * host2netl_asm() converts param from host byte order to network byte order (i.e., Big Endian)
 *------------------------------------------------------------------------
 */

.text								#section declaration
.globl host2netl_asm            	#loader. They conventionally recognize _start as their

host2netl_asm:

			pushl %ebp
			movl %esp, %ebp
			movl 8(%ebp), %eax 		#Put value of param into EAX 
			xchg %ah, %al
			ror  $16, %eax   			#ror destination, count ; the shifted bits are rotated to the other end
			xchg %ah, %al
			leave
			ret 					#Exit function




