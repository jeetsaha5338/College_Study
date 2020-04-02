--------------------------------------------------------------------------------
-- Copyright (c) 1995-2003 Xilinx, Inc.
-- All Right Reserved.
--------------------------------------------------------------------------------
--   ____  ____ 
--  /   /\/   / 
-- /___/  \  /    Vendor: Xilinx 
-- \   \   \/     Version : 8.1i
--  \   \         Application : ISE
--  /   /         Filename : Exp_2_Vec_Res.vhw
-- /___/   /\     Timestamp : Tue Jul 25 11:49:23 2017
-- \   \  /  \ 
--  \___\/\___\ 
--
--Command: 
--Design Name: Exp_2_Vec_Res
--Device: Xilinx
--

library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.STD_LOGIC_ARITH.ALL;
use IEEE.STD_LOGIC_UNSIGNED.ALL;
USE IEEE.STD_LOGIC_TEXTIO.ALL;
USE STD.TEXTIO.ALL;

ENTITY Exp_2_Vec_Res IS
END Exp_2_Vec_Res;

ARCHITECTURE testbench_arch OF Exp_2_Vec_Res IS
    FILE RESULTS: TEXT OPEN WRITE_MODE IS "results.txt";

    COMPONENT Exp_2_Vec
        PORT (
            a : In std_logic_vector (3 DownTo 0);
            y : Out std_logic
        );
    END COMPONENT;

    SIGNAL a : std_logic_vector (3 DownTo 0) := "0000";
    SIGNAL y : std_logic := '0';

    SHARED VARIABLE TX_ERROR : INTEGER := 0;
    SHARED VARIABLE TX_OUT : LINE;

    BEGIN
        UUT : Exp_2_Vec
        PORT MAP (
            a => a,
            y => y
        );

        PROCESS
            PROCEDURE CHECK_y(
                next_y : std_logic;
                TX_TIME : INTEGER
            ) IS
                VARIABLE TX_STR : String(1 to 4096);
                VARIABLE TX_LOC : LINE;
                BEGIN
                IF (y /= next_y) THEN
                    STD.TEXTIO.write(TX_LOC, string'("Error at time="));
                    STD.TEXTIO.write(TX_LOC, TX_TIME);
                    STD.TEXTIO.write(TX_LOC, string'("ns y="));
                    IEEE.STD_LOGIC_TEXTIO.write(TX_LOC, y);
                    STD.TEXTIO.write(TX_LOC, string'(", Expected = "));
                    IEEE.STD_LOGIC_TEXTIO.write(TX_LOC, next_y);
                    STD.TEXTIO.write(TX_LOC, string'(" "));
                    TX_STR(TX_LOC.all'range) := TX_LOC.all;
                    STD.TEXTIO.writeline(RESULTS, TX_LOC);
                    STD.TEXTIO.Deallocate(TX_LOC);
                    ASSERT (FALSE) REPORT TX_STR SEVERITY ERROR;
                    TX_ERROR := TX_ERROR + 1;
                END IF;
            END;
            BEGIN
                -- -------------  Current Time:  40ns
                WAIT FOR 40 ns;
                a <= "0001";
                -- -------------------------------------
                -- -------------  Current Time:  80ns
                WAIT FOR 40 ns;
                a <= "0011";
                -- -------------------------------------
                -- -------------  Current Time:  120ns
                WAIT FOR 40 ns;
                a <= "0100";
                -- -------------------------------------
                -- -------------  Current Time:  160ns
                WAIT FOR 40 ns;
                a <= "0101";
                -- -------------------------------------
                -- -------------  Current Time:  200ns
                WAIT FOR 40 ns;
                a <= "0110";
                -- -------------------------------------
                -- -------------  Current Time:  240ns
                WAIT FOR 40 ns;
                a <= "0111";
                -- -------------------------------------
                -- -------------  Current Time:  280ns
                WAIT FOR 40 ns;
                a <= "1000";
                -- -------------------------------------
                -- -------------  Current Time:  320ns
                WAIT FOR 40 ns;
                a <= "1010";
                -- -------------------------------------
                -- -------------  Current Time:  360ns
                WAIT FOR 40 ns;
                a <= "1011";
                -- -------------------------------------
                -- -------------  Current Time:  400ns
                WAIT FOR 40 ns;
                CHECK_y('0', 400);
                a <= "1100";
                -- -------------------------------------
                -- -------------  Current Time:  440ns
                WAIT FOR 40 ns;
                a <= "1101";
                -- -------------------------------------
                -- -------------  Current Time:  480ns
                WAIT FOR 40 ns;
                a <= "1110";
                -- -------------------------------------
                -- -------------  Current Time:  520ns
                WAIT FOR 40 ns;
                a <= "1111";
                -- -------------------------------------
                -- -------------  Current Time:  1000ns
                WAIT FOR 480 ns;
                CHECK_y('0', 1000);

                IF (TX_ERROR = 0) THEN
                    STD.TEXTIO.write(TX_OUT, string'("No errors or warnings"));
                    STD.TEXTIO.writeline(RESULTS, TX_OUT);
                    ASSERT (FALSE) REPORT
                      "Simulation successful (not a failure).  No problems detected."
                      SEVERITY FAILURE;
                ELSE
                    STD.TEXTIO.write(TX_OUT, TX_ERROR);
                    STD.TEXTIO.write(TX_OUT,
                        string'(" errors found in simulation"));
                    STD.TEXTIO.writeline(RESULTS, TX_OUT);
                    ASSERT (FALSE) REPORT "Errors found during simulation"
                         SEVERITY FAILURE;
                END IF;
            END PROCESS;

    END testbench_arch;

