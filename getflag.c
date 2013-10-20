void getstoredcrc(int param1);
void getstoredkeyinput(int param1);
checkstoredcrc(int param2, int param1);
checkkey(int param1);
printflag(int param1);
str2md5(int param1, int param2);
checkhash(int param1);

// address: 0x8048ecc
int main(int argc, char **argv, char **envp) {
    int local15; 		// r24
    int local18; 		// r28
    int local19; 		// r29

    *(int*)(local18 - 4) = local19;
    *(int*)(local18 - 72) = argv;
    *(int*)(local18 - 8) = *(int*)20;
    *(int*)(local18 - 100) = local18 - 60;
    getstoredcrc(local18 - 60);
    *(int*)(local18 - 100) = local18 - 26;
    getstoredkeyinput(local18 - 26);
    *(int*)(local18 - 96) = local18 - 26;
    *(int*)(local18 - 100) = 0x80490de;
    printf("got keyinput in main: %s\n", local18 - 26);
    *(int*)(local18 - 96) = local18 - 60;
    *(int*)(local18 - 100) = 0x80490f8;
    printf("got crc in main: %s\n", local18 - 60);
    *(int*)(local18 - 96) = local18 - 26;
    *(int*)(local18 - 100) = local18 - 60;
    local15 = checkstoredcrc(local18 - 60, local18 - 26);
    if (local15 != 0) {
        *(int*)(local18 - 100) = 0x804911f;
        puts("crc check failed!");
        *(int*)(local18 - 100) = 1;
        proc1();
L5:
        *(int*)(local18 - 100) = local18 - 26;
        printflag(local18 - 60);
        *(int*)(local18 - 100) = 0x8049131;
        puts("good");
        *(int*)(local18 - 100) = 0;
        proc1();
    } else {
        *(int*)(local18 - 100) = 0x804910d;
        puts("crc check passed!");
        *(int*)(local18 - 100) = local18 - 26;
        local15 = checkkey(local18 - 26);
        if (local15 == 0) {
            goto L5;
        }
    }
    *(int*)(local18 - 100) = 0x8049136;
    puts("bad");
    *(int*)(local18 - 100) = 1;
    proc1();
    *(int*)(local18 - 104) = local18 - 4;
    return local15;
}

// address: 0x8048b44
void getstoredcrc(int param1) {
    char local0[34]; 		// m[r28 - 50]
    int local15; 		// r24
    int local18; 		// r28

    local15 = fopen("flag.dat", "r");
    fseek(local15, 0xc86, 0);
    fgets(local0, 33, local15);
    strncpy(param1, local0, 34);
    fclose(local15);
    if ((0 ^ *(int*)20) != 0) {
        __stack_chk_fail();
    }
    return;
}

// address: 0x8048aa3
void getstoredkeyinput(int param1) {
    char local0[18]; 		// m[r28 - 34]
    int local15; 		// r24
    int local18; 		// r28

    local15 = fopen("flag.dat", "r");
    fseek(local15, 0xc76, 0);
    fgets(local0, 17, local15);
    strncpy(param1, local0, 18);
    fclose(local15);
    if ((0 ^ *(int*)20) != 0) {
        __stack_chk_fail();
    }
    return;
}

// address: 0x8048c67
checkstoredcrc(int param2, int param1) {
    int local11; 		// r28
    int local8; 		// r24

    local8 = strlen(param1);
    local8 = str2md5(param1, local8);
    local8 = strcmp(param2, local8);
    return local8;
}

// address: 0x8048cdc
checkkey(int param1) {
    char local0[1024]; 		// m[r28 - 22]
    char local1[1024]; 		// m[r28 - 19]
    int local21; 		// r24{220}
    int local22; 		// r24{229}
    int local23; 		// r24{211}
    int local24; 		// r24{202}
    int local33; 		// r24{273}
    char local34; 		// r8
    char local35; 		// r24
    char local38; 		// r28

    printf("checking key: %s\n", param1);
    local34 = (unsigned char) param1;
    local35 = strlen(param1);
    local33 = local35;
    if (local35 != 16) {
L1:
        local35 = local33;
    } else {
        local34 = (unsigned char) param1;
        local35 = strncmp(param1, "b0", 2);
        local33 = local35;
        if (local35 != 0) {
            goto L1;
        } else {
            local35 = (param1[14]);
            if ((unsigned char) local35 != 48) {
L2:
                local35 = 1;
                local34 = 1;
            } else {
                local35 = (param1[15]);
                if ((unsigned char) local35 != 98) {
                    goto L2;
                } else {
                    local35 = checkhash(local38 - 41); /* Warning: also results in local34 */
                    local33 = local35;
                    if (local35 != 0) {
                        goto L1;
                    } else {
                        time();
                        localtime();
                        sprintf(local0, "%d", *(int*)(local35 + 16) + 1);
                        local34 = (unsigned char) local38 - 22;
                        local35 = strcmp(local0, local1);
                        local33 = local35;
                        if (local35 != 0) {
                            goto L1;
                        } else {
                            local35 = (param1[2]);
                            local34 = (unsigned char) local35;
                            local33 = local35;
                            if ((unsigned char) local35 != 55) {
                                goto L1;
                            } else {
                                local35 = (param1[3]);
                                local34 = (unsigned char) local35;
                                local33 = local35;
                                if ((unsigned char) local35 != 100) {
                                    goto L1;
                                } else {
                                    local24 = (param1[4]);
                                    local23 = (param1[8]);
                                    local21 = (param1[5]);
                                    local22 = (param1[7]);
                                    local34 = (unsigned char) local22;
                                    local33 = local22;
                                    local33 = local22;
                                    if ((unsigned char) local24 != 98) {
                                        goto L1;
                                    } else {
                                        if ((unsigned char) local23 != 102) {
                                            goto L1;
                                        } else {
                                            local35 = ((unsigned char) local21);
                                            local34 = (unsigned char) ((unsigned char) local21);
                                            local33 = local35;
                                            local33 = local35;
                                            if ((unsigned char) ((unsigned char) local21) != (unsigned char) local22) {
                                                goto L1;
                                            } else {
                                                if ((unsigned char) local21 != 101) {
                                                    goto L1;
                                                } else {
                                                    local35 = 0;
                                                    local34 = 0;
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return local35; /* WARNING: Also returning: local34 */
}

// address: 0x8048e99
printflag(int param1) {
    int local5; 		// r8
    int local6; 		// r24
    int local9; 		// r28

    local6 = strlen(param1);
    local6 = str2md5(param1, local6); /* Warning: also results in local5 */
    printf("The flag is: %s\n", local6);
    return local5;
}

// address: 0x80489a4
str2md5(int param1, int param2) {
    int local11; 		// r24{20}
    int local24; 		// r24
    int local27; 		// r28
    int local8; 		// m[r28 - 36]

    local11 = malloc(33);
    MD5_Init();
    while (param2 > 0) {
        if (param2 <= 512) {
            MD5_Update();
        } else {
            MD5_Update();
        }
        param2 = param2 - 512;
    }
    MD5_Final();
    local8 = 0;
    while (local8 <= 15) {
        snprintf();
        local8++;
    }
    local24 = local11;
    return local24; /* WARNING: Also returning: (unsigned char) local11 */
}

// address: 0x8048c9e
checkhash(int param1) {
    int local11; 		// r28
    int local7; 		// r8
    int local8; 		// r24

    local8 = strlen(param1);
    local8 = str2md5(param1, local8); /* Warning: also results in local7 */
    local8 = strcmp(local8, "d5ca322453f2986b752e58b11af83d96");
    return local8; /* WARNING: Also returning: local7 */
}
