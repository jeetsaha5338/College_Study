--------------------------------------------------------------------------------
-- Copyright (c) 1995-2003 Xilinx, Inc.
-- All Right Reserved.
--------------------------------------------------------------------------------
--   ____  ____ 
--  /   /\/   / 
-- /___/  \  /    Vendor: Xilinx 
-- \   \   \/     Version : 8.1i
--  \   \         Application : ISE
--  /   /         Filename : mux8bybahav_tb.vhw
-- /___/   /\     Timestamp : Mon Aug 21 23:43:16 2017
-- \   \  /  \ 
--  \___\/\___\ 
--
--Command: 
--Design Name: mux8bybahav_tb
--Device: Xilinx
--

library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.STD_LOGIC_ARITH.ALL;
use IEEE.STD_LOGIC_UNSIGNED.ALL;
USE IEEE.STD_LOGIC_TEXTIO.ALL;
USE STD.TEXTIO.ALL;

ENTITY mux8bybahav_tb IS
END mux8bybahav_tb;

ARCHITECTURE testbench_arch OF mux8bybahav_tb IS
    FILE RESULTS: TEXT OPEN WRITE_MODE IS "results.txt";

    COMPONENT mux8bybehav
        PORT (
            i : In std_logic_vector (7 DownTo 0);
            s : In std_logic_vector (2 DownTo 0);
            e : In std_logic;
            y : Out std_logic
        );
    END COMPONENT;

    SIGNAL i : std_logic_vector (7 DownTo 0) := "00000000";
    SIGNAL s : std_logic_vector (2 DownTo 0) := "000";
    SIGNAL e : std_logic := '1';
    SIGNAL y : std_logic := '0';

    SHARED VARIABLE TX_ERROR : INTEGER := 0;
    SHARED VARIABLE TX_OUT : LINE;

    BEGIN
        UUT : mux8bybehav
        PORT MAP (
            i => i,
            s => s,
            e => e,
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
                i <= "00000001";
                -- -------------------------------------
                -- -------------  Current Time:  80ns
                WAIT FOR 40 ns;
                i <= "00000000";
                s <= "001";
                -- -------------------------------------
                -- -------------  Current Time:  120ns
                WAIT FOR 40 ns;
                i <= "00000010";
                -- -------------------------------------
                -- -------------  Current Time:  160ns
                WAIT FOR 40 ns;
                i <= "00000000";
                s <= "010";
                -- -------------------------------------
                -- -------------  Current Time:  200ns
                WAIT FOR 40 ns;
                i <= "00000100";
                -- -------------------------------------
                -- -------------  Current Time:  240ns
                WAIT FOR 40 ns;
                i <= "00000000";
                s <= "011";
                -- -------------------------------------
                -- -------------  Current Time:  280ns
                WAIT FOR 40 ns;
                i <= "00001000";
                -- -------------------------------------
                -- -------------  Current Time:  320ns
                WAIT FOR 40 ns;
                i <= "00000000";
                s <= "000";
                -- -------------------------------------
                -- -------------  Current Time:  1000ns
                WAIT FOR 680 ns;
                e <= '0';

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

