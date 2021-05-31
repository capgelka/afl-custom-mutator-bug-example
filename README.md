## Readme

This repo contains an example to reproduce https://github.com/AFLplusplus/AFLplusplus/issues/937

### Steps

```
make all
export AFL_CUSTOM_MUTATOR_LIBRARY="./libafl_custom_mutator.so;./libafl_custom_postprocessor.so"
afl-fuzz -i seed -o OUT -- ./example @@
```

Stacktrace:

```
[+] Found a free CPU core, try binding to #0.
[*] Loading custom mutator library from './libafl_custom_mutator.so'...
[*] optional symbol 'afl_custom_fuzz_count' not found.
[*] optional symbol 'afl_custom_post_process' not found.
[*] optional symbol 'afl_custom_init_trim' not found.
[*] optional symbol 'afl_custom_trim' not found.
[*] optional symbol 'afl_custom_post_trim' not found.
[*] optional symbol 'afl_custom_havoc_mutation' not found.
[*] optional symbol 'afl_custom_havoc_mutation_probability' not found.
[*] optional symbol 'afl_custom_queue_get' not found.
[*] optional symbol 'afl_custom_queue_new_entry' not found
[*] Symbol 'afl_custom_describe' not found.
[+] Custom mutator './libafl_custom_mutator.so' installed successfully.
[*] Loading custom mutator library from './libafl_custom_postprocessor.so'...
[!] WARNING: Symbol 'afl_custom_fuzz' not found. Try 'afl_custom_mutator'.
[!] WARNING: Symbol 'afl_custom_mutator' not found.
[*] optional symbol 'afl_custom_fuzz_count' not found.
[*] optional symbol 'afl_custom_init_trim' not found.
[*] optional symbol 'afl_custom_trim' not found.
[*] optional symbol 'afl_custom_post_trim' not found.
[*] optional symbol 'afl_custom_havoc_mutation' not found.
[*] optional symbol 'afl_custom_havoc_mutation_probability' not found.
[*] optional symbol 'afl_custom_queue_get' not found.
[*] optional symbol 'afl_custom_queue_new_entry' not found
[*] Symbol 'afl_custom_describe' not found.
[+] Custom mutator './libafl_custom_postprocessor.so' installed successfully.
[*] Scanning 'seed'...
[+] Loaded a total of 2 seeds.
[*] Creating hard links for all input files...
[*] Validating target binary...
[*] Spinning up the fork server...
[Detaching after fork from child process 32120]
[+] All right - fork server is up.
[*] No auto-generated dictionary tokens to reuse.
[*] Attempting dry run with 'id:000000,time:0,orig:input1'...

Program received signal SIGSEGV, Segmentation fault.
0x00007ffff7fc2181 in afl_custom_post_process (data=0x5555555d82d0, buf=0x0, buf_size=0x5, out_buf=0x7fffffff7a50) at custom_postprocessor.c:45
45	        if (buf[i] > 127) {
[ Legend: Modified register | Code | Heap | Stack | String ]
─────────────────────────────────────────────────────────────────────── registers ────
$rax   : 0x0               
$rbx   : 0x00007ffff748af40  →  0x0000000000000001
$rcx   : 0x0               
$rdx   : 0x5               
$rsp   : 0x00007fffffff7a30  →  0x00007ffff7438010  →  0x0000000000000000
$rbp   : 0x00007fffffff7a30  →  0x00007ffff7438010  →  0x0000000000000000
$rsi   : 0x0               
$rdi   : 0x00005555555d82d0  →  0x00005555555d82b0  →  "__AFL_TARGET_PID1=32120"
$rip   : 0x00007ffff7fc2181  →  <afl_custom_post_process+49> movzx edx, BYTE PTR [rax+rcx*1]
$r8    : 0xdde05           
$r9    : 0x00007ffff7fc2150  →  <afl_custom_post_process+0> push rbp
$r10   : 0x0               
$r11   : 0x00007ffff743a600  →  0x0000000200000100
$r12   : 0x00007fffffff7a50  →  0x0000000000000000
$r13   : 0x00007ffff748af40  →  0x0000000000000001
$r14   : 0x00005555555dac58  →  0x00007f0a41414141
$r15   : 0x5               
$eflags: [zero CARRY parity ADJUST SIGN trap INTERRUPT direction overflow RESUME virtualx86 identification]
$cs: 0x0033 $ss: 0x002b $ds: 0x0000 $es: 0x0000 $fs: 0x0000 $gs: 0x0000 
─────────────────────────────────────────────────────────────────────────── stack ────
0x00007fffffff7a30│+0x0000: 0x00007ffff7438010  →  0x0000000000000000	 ← $rsp, $rbp
0x00007fffffff7a38│+0x0008: 0x0000555555562186  →  <write_to_testcase.part+134> mov r10, QWORD PTR [rsp+0x10]
0x00007fffffff7a40│+0x0010: 0x00007ffff7d996a0  →  0x00000000fbad2a84
0x00007fffffff7a48│+0x0018: 0x00000005ffff7b10
0x00007fffffff7a50│+0x0020: 0x0000000000000000	 ← $r12
0x00007fffffff7a58│+0x0028: 0xaec16e048d0ee900
0x00007fffffff7a60│+0x0030: 0x00007fffffff7a90  →  0x00000000000003e8
0x00007fffffff7a68│+0x0038: 0x00005555555da500  →  0x00005555555da690  →  "OUT/default/queue/id:000000,time:0,orig:input1"
───────────────────────────────────────────────────────────────────── code:x86:64 ────
   0x7ffff7fc2173 <afl_custom_post_process+35> jae    0x7ffff7fc21b3 <afl_custom_post_process+99>
   0x7ffff7fc2179 <afl_custom_post_process+41> mov    rax, QWORD PTR [rbp-0x10]
   0x7ffff7fc217d <afl_custom_post_process+45> movsxd rcx, DWORD PTR [rbp-0x24]
 → 0x7ffff7fc2181 <afl_custom_post_process+49> movzx  edx, BYTE PTR [rax+rcx*1]
   0x7ffff7fc2185 <afl_custom_post_process+53> cmp    edx, 0x7f
   0x7ffff7fc2188 <afl_custom_post_process+56> jle    0x7ffff7fc21a0 <afl_custom_post_process+80>
   0x7ffff7fc218e <afl_custom_post_process+62> mov    rax, QWORD PTR [rbp-0x10]
   0x7ffff7fc2192 <afl_custom_post_process+66> movsxd rcx, DWORD PTR [rbp-0x24]
   0x7ffff7fc2196 <afl_custom_post_process+70> movzx  edx, BYTE PTR [rax+rcx*1]
──────────────────────────────────────────────── source:custom_postproc[...].c+45 ────
     40	                                unsigned char **out_buf)
     41	 
     42	 {
     43	 
     44	     for (int i = 0; i < buf_size; i++) {
                 // i=0x0, buf=0x00007fffffff7a20  →  0x0000000000000000
 →   45	         if (buf[i] > 127) {
     46	             buf[i] -= 127;
     47	         }
     48	     }
     49	     *out_buf = buf;
     50	     return buf_size;
───────────────────────────────────────────────────────────────────────── threads ────
[#0] Id 1, Name: "afl-fuzz", stopped, reason: SIGSEGV
─────────────────────────────────────────────────────────────────────────── trace ────
[#0] 0x7ffff7fc2181 → afl_custom_post_process(data=0x5555555d82d0, buf=0x0, buf_size=0x5, out_buf=0x7fffffff7a50)
[#1] 0x555555562186 → write_to_testcase(afl=0x7ffff7438010, mem=0x5555555dac58, len=0x5)
[#2] 0x55555556b5b5 → write_to_testcase(len=<optimized out>, mem=<optimized out>, afl=0x7ffff7438010)
[#3] 0x55555556b5b5 → calibrate_case(afl=0x7ffff7438010, q=0x5555555da500, use_mem=0x5555555dac58 "AAAA\n\177", handicap=0x0, from_queue=0x1)
[#4] 0x5555555726ef → perform_dry_run(afl=0x7ffff7438010)
[#5] 0x55555555edd8 → main(argc=<optimized out>, argv_orig=<optimized out>, envp=<optimized out>)
──────────────────────────────────────────────────────────────────────────────────────
gef➤  

```
