--------------------------------------------------------------------------------
-- Copyright (c) 1995-2003 Xilinx, Inc.
-- All Right Reserved.
--------------------------------------------------------------------------------
--   ____  ____ 
--  /   /\/   / 
-- /___/  \  /    Vendor: Xilinx 
-- \   \   \/     Version : 8.1i
--  \   \         Application : ISE
--  /   /         Filename : XNORGATE_RES.vhw
-- /___/   /\     Timestamp : Tue Jul 18 12:09:38 2017
-- \   \  /  \ 
--  \___\/\___\ 
--
--Command: 
--Design Name: XNORGATE_RES
--Device: Xilinx
--

library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.STD_LOGIC_ARITH.ALL;
use IEEE.STD_LOGIC_UNSIGNED.ALL;
USE IEEE.STD_LOGIC_TEXTIO.ALL;
USE STD.TEXTIO.ALL;

ENTITY XNORGATE_RES IS
END XNORGATE_RES;

ARCHITECTURE testbench_arch OF XNORGATE_RES IS
    FILE RESULTS: TEXT OPEN WRITE_MODE IS "results.txt";

    COMPONENT XNOR_GATE
        PORT (
            a : In std_logic;
            b : In std_logic;
            y : Out std_logic
        );
    END COMPONENT;

    SIGNAL a : std_logic := '0';
    SIGNAL b : std_logic := '0';
    SIGNAL y : std_logic := '0';

    SHARED VARIABLE TX_ERROR : INTEGER := 0;
    SHARED VARIABLE TX_OUT : LINE;

    BEGIN
        UUT : XNOR_GATE
        PORT MAP (
            a => a,
            b => b,
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
                -- -------------  Current Time:  200ns
                WAIT FOR 200 ns;
                b <= '1';
                -- -------------------------------------
                -- -------------  Current Time:  300ns
                WAIT FOR 100 ns;
                a <= '1';
                b <= '0';
                -- -------------------------------------
                -- -------------  Current Time:  400ns
                WAIT FOR 100 ns;
                b <= '1';
                -- -------------------------------------
                -- -------------  Current Time:  600ns
                WAIT FOR 200 ns;
                a <= '0';
                b <= '0';
                WAIT FOR 400 ns;

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
