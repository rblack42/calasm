; test code for assembler code
    .data
size:   DB  5
array:  DW  27
        DW  53
        DW  99
        DW  400

    .code
main:
    MOV R0, size
    MOV R1, array   ; address of array
    MOV R2, 0       ; sum is stored here
    MOV R3, count;  ; loop counter
loop:
    ADD R2, WORD [R1]
    ADD R2, 2
    DEC R3
    JNZ loop
    OUT R3
    HALT

    


