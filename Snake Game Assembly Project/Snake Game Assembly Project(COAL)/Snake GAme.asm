[org 0x100]

jmp start;
score: dw 0;
oldisr: dd 0;
oldtimer: dd 0;
flag: dw 0;
tickcount: dw 0;
Rflag: dw 0;
Lflag: dw 0;
Uflag: dw 0;
Dflag: dw 0;

clrscr:
push bp;
push es;
push ax;
push bx;
push cx;
mov ax,0xb800;
mov es,ax;
xor di,di;
mov cx,2000;
mov ax,0x0720;
cld;
rep stosw;

pop cx;
pop bx;
pop ax;
pop es;
pop bp;
ret;

printgreen:
push bp;
push es;
push ax;
push bx;
push cx;
mov ax,0xb800;
mov es,ax;
xor di,di;
mov cx,2000;
mov ax,0x2020;
cld;
rep stosw;

pop cx;
pop bx;
pop ax;
pop es;
pop bp;
ret;

printred:
push bp;
push es;
push ax;
push bx;
push cx;
mov ax,0xb800;
mov es,ax;
xor di,di;

mov word[es:di],0x072A;
add di,2;


mov cx,48;
mov ax,0x2020;
cld;
rep stosw;

mov cx,2;
mov ax,0x4020;
cld;
rep stosw;

mov cx,100;
mov ax,0x2020;
cld;
rep stosw;

mov cx,2;
mov ax,0x4020;
cld;
rep stosw;

mov cx,150;
mov ax,0x2020;
cld;
rep stosw;

mov cx,2;
mov ax,0x4020;
cld;
rep stosw;

mov cx,20;
mov ax,0x2020;
cld;
rep stosw;

mov cx,2;
mov ax,0x4020;
cld;
rep stosw;


mov cx,250;
mov ax,0x2020;
cld;
rep stosw;

mov cx,2;
mov ax,0x4020;
cld;
rep stosw;

mov cx,20;
mov ax,0x2020;
cld;
rep stosw;

mov cx,2;
mov ax,0x4020;
cld;
rep stosw;

mov cx,20;
mov ax,0x2020;
cld;
rep stosw;

mov cx,2;
mov ax,0x4020;
cld;
rep stosw;

mov cx,250;
mov ax,0x2020;
cld;
rep stosw;

mov cx,2;
mov ax,0x4020;
cld;
rep stosw;

mov cx,100;
mov ax,0x2020;
cld;
rep stosw;

mov cx,2;
mov ax,0x4020;
cld;
rep stosw;

mov cx,100;
mov ax,0x2020;
cld;
rep stosw;

mov cx,2;
mov ax,0x4020;
cld;
rep stosw;

mov cx,100;
mov ax,0x2020;
cld;
rep stosw;

mov cx,2;
mov ax,0x4020;
cld;
rep stosw;

mov cx,150;
mov ax,0x2020;
cld;
rep stosw;

mov cx,2;
mov ax,0x4020;
cld;
rep stosw;

mov cx,50;
mov ax,0x2020;
cld;
rep stosw;

mov cx,2;
mov ax,0x4020;
cld;
rep stosw;

mov cx,20;
mov ax,0x2020;
cld;
rep stosw;

mov cx,2;
mov ax,0x4020;
cld;
rep stosw;

mov cx,20;
mov ax,0x2020;
cld;
rep stosw;

mov cx,2;
mov ax,0x4020;
cld;
rep stosw;

mov cx,20;
mov ax,0x2020;
cld;
rep stosw;

mov cx,2;
mov ax,0x4020;
cld;
rep stosw;

mov cx,40;
mov ax,0x2020;
cld;
rep stosw;

mov cx,2;
mov ax,0x4020;
cld;
rep stosw;

mov cx,100;
mov ax,0x2020;
cld;
rep stosw;

mov cx,2;
mov ax,0x4020;
cld;
rep stosw;

mov cx,100;
mov ax,0x2020;
cld;
rep stosw;

mov cx,2;
mov ax,0x4020;
cld;
rep stosw;

mov cx,200;
mov ax,0x2020;
cld;
rep stosw;

mov cx,2;
mov ax,0x4020;
cld;
rep stosw;

mov cx,100;
mov ax,0x2020;
cld;
rep stosw;

pop cx;
pop bx;
pop ax;
pop es;
pop bp;
ret;

printasterikR:
push ax;
push bx;
push cx;
push es;
push si;
push di;
mov ax,0xb800;
mov es,ax;
mov di,0;
l1:
	cmp word[es:di],0x072A;
	je nextstep1;
	add di,2;
	cmp di,4000;
	jne l1;
jmp poping1;
nextstep1;
mov word[es:di],0x0720;
add di,2;
cmp word[es:di],0x2020;
jne next1;
inc word[score];

next1:
mov word[Rflag],1;
mov word[Dflag],0;
mov word[Lflag],0;
mov word[Uflag],0;
;----------update
cmp word[es:di],0x4020;
jne moveon1;
mov word[flag],1;
jmp poping1;

moveon1:
mov word[es:di],0x072A;

;inc word[tickcount];

poping1:
pop di;
pop si;
pop es;
pop cx;
pop bx;
pop ax;
ret;

printasterikL:
push ax;
push bx;
push cx;
push es;
push si;
push di;
mov ax,0xb800;
mov es,ax;
mov di,0;
l2:
	cmp word[es:di],0x072A;
	je nextstep2;
	add di,2;
	cmp di,4000;
	jne l2;
jmp poping2;
nextstep2;
mov word[es:di],0x0720;
; here compare and increase score
sub di,2;
cmp word[es:di],0x2020;
jne next2;
inc word[score];
next2:
mov word[Rflag],0;
mov word[Dflag],0;
mov word[Lflag],1;
mov word[Uflag],0;
;----------update
cmp word[es:di],0x4020;
jne moveon2;
mov word[flag],1;
jmp poping2;

moveon2:
mov word[es:di],0x072A;
;inc word[score];
;inc word[tickcount];

poping2;
pop di;
pop si;
pop es;
pop cx;
pop bx;
pop ax;
ret;

printasterikU:
push ax;
push bx;
push cx;
push es;
push si;
push di;
mov ax,0xb800;
mov es,ax;
mov di,0;

l3:
	cmp word[es:di],0x072A;
	je nextstep3;
	add di,2;
	cmp di,4000;
	jne l3;
jmp poping3;
nextstep3;
mov word[es:di],0x0720;
; here compare and increase score
sub di,160;
;------27------
cmp di,-1;
jnl step3;
mov word[flag],1;
jmp poping3;
step3:
;------27-----
cmp word[es:di],0x2020;
jne next3;
inc word[score];
next3:
mov word[Rflag],0;
mov word[Dflag],0;
mov word[Lflag],0;
mov word[Uflag],1;
;----------update
cmp word[es:di],0x4020;
jne moveon3;
mov word[flag],1;
jmp poping3;

moveon3:
mov word[es:di],0x072A;

;inc word[tickcount];

poping3;
pop di;
pop si;
pop es;
pop cx;
pop bx;
pop ax;
ret;

printasterikD:
push ax;
push bx;
push cx;
push es;
push si;
push di;
mov ax,0xb800;
mov es,ax;
mov di,0;
l4:
	cmp word[es:di],0x072A;
	je nextstep4;
	add di,2;
	cmp di,4000;
	jne l4;

jmp poping4;
nextstep4;
mov word[es:di],0x0720;
; here compare and increase score
add di,160;
;------27------
cmp di,4000;
jb step4;
mov word[flag],1;
jmp poping4;
step4:
;------27------
cmp word[es:di],0x2020;
jne next4;
inc word[score];
next4:
mov word[Rflag],0;
mov word[Dflag],1;
mov word[Lflag],0;
mov word[Uflag],0;
;----------update
cmp word[es:di],0x4020;
jne moveon4;
mov word[flag],1;
jmp poping4;

moveon4:
mov word[es:di],0x072A;
;inc word[score];
;inc word[tickcount];

poping4;
pop di;
pop si;
pop es;
pop cx;
pop bx;
pop ax;
ret;



kbisr:
in al,0x60;
cmp al,0x4D;for right
jne nextcmp;
call printasterikR;

nextcmp:
cmp al,0x48
jne nextcmp1;
call printasterikU;

nextcmp1:
cmp al,0x4B;
jne nextcmp2 ;
call printasterikL

nextcmp2:
cmp al,0x50;
jne nomatch;
call printasterikD

nomatch:
mov al,0x20;
out 0x20,al;
iret;



printnum:
 push bp 
 mov bp, sp 
 push es 
 push ax 
 push bx 
 push cx 
 push dx 
 push di 
 mov ax, 0xb800 
 mov es, ax ; 
 mov ax, [bp+4] ;
 mov bx, 10 ; 
 mov cx, 0 ; 
nextdigit: mov dx, 0 ; 
 div bx ; 
 add dl, 0x30 ; 
 push dx ; 
 inc cx ; 
 cmp ax, 0 ; 
 jnz nextdigit ; 
 mov di, 140 ; 
nextpos: pop dx ;
 mov dh, 0x07 ; 
 mov [es:di], dx ; 
 add di, 2 ;
 loop nextpos ;
 pop di 
 pop dx 
 pop cx 
 pop bx 
 pop ax 
 pop es;
 pop bp;
 ret 2;

timer:

push ax;
;push word[tickcount];
push word[score];

call printnum;
add word[tickcount],1;
cmp word[tickcount],18;
jne exitpop;
mov word[tickcount],0
cmp word[Rflag],1;
jne moveleft;
call printasterikR;

moveleft:
cmp word[Lflag],1;
jne moveup;
call printasterikL;

moveup:
cmp word[Uflag],1;
jne movedown;
call printasterikU;

movedown:
cmp word[Dflag],1;
jne exitpop;
call printasterikD;


exitpop:
mov al,0x20;
out 0x20,al;
pop ax;
iret;


start:
call clrscr;
call printgreen;
call printred;
xor ax,ax;
mov es,ax;
mov ax,[es:9*4];
mov [oldisr],ax;
mov ax,[es:9*4+2];
mov [oldisr+2],ax;
mov ax,[es:8*4];
mov [oldtimer],ax;
mov ax,[es:8*4+2];
mov [oldtimer+2],ax;
cli;
mov word[es:9*4],kbisr;
mov [es:9*4+2],cs;
mov word[es:8*4],timer;
mov [es:8*4+2],cs;
sti;




infi:
cmp word[flag],1;
je terminatestep;
jmp infi;


terminatestep:
mov ax,[oldtimer];
mov bx,[oldtimer+2];
cli;
mov [es:8*4],ax;
mov [es:8*4+2],bx;
sti;

mov ax,[oldisr];
mov bx,[oldisr+2];
cli;
mov [es:9*4],ax;
mov [es:9*4+2],bx;
sti;

call clrscr;
mov ax,0x4c00;
int 21h