--------------------------------------------------------------------------------
-- Copyright (c) 1995-2003 Xilinx, Inc.
-- All Right Reserved.
--------------------------------------------------------------------------------
--   ____  ____ 
--  /   /\/   / 
-- /___/  \  /    Vendor: Xilinx 
-- \   \   \/     Version : 8.1i
--  \   \         Application : ISE
--  /   /         Filename : SIPO_RES1.vhw
-- /___/   /\     Timestamp : Tue Oct 10 12:17:57 2017
-- \   \  /  \ 
--  \___\/\___\ 
--
--Command: 
--Design Name: SIPO_RES1
--Device: Xilinx
--

library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.STD_LOGIC_ARITH.ALL;
use IEEE.STD_LOGIC_UNSIGNED.ALL;
USE IEEE.STD_LOGIC_TEXTIO.ALL;
USE STD.TEXTIO.ALL;

ENTITY SIPO_RES1 IS
END SIPO_RES1;

ARCHITECTURE testbench_arch OF SIPO_RES1 IS
    FILE RESULTS: TEXT OPEN WRITE_MODE IS "results.txt";

    COMPONENT SIPO
        PORT (
            din : In std_logic;
            clk : In std_logic;
            qout : Out std_logic_vector (7 DownTo 0)
        );
    END COMPONENT;

    SIGNAL din : std_logic := '0';
    SIGNAL clk : std_logic := '0';
    SIGNAL qout : std_logic_vector (7 DownTo 0) := "00000000";

    SHARED VARIABLE TX_ERROR : INTEGER := 0;
    SHARED VARIABLE TX_OUT : LINE;

    constant PERIOD : time := 80 ns;
    constant DUTY_CYCLE : real := 0.5;
    constant OFFSET : time := 0 ns;

    BEGIN
        UUT : SIPO
        PORT MAP (
            din => din,
            clk => clk,
            qout => qout
        );

        PROCESS    -- clock process for clk
        BEGIN
            WAIT for OFFSET;
            CLOCK_LOOP : LOOP
                clk <= '0';
                WAIT FOR (PERIOD - (PERIOD * DUTY_CYCLE));
                clk <= '1';
                WAIT FOR (PERIOD * DUTY_CYCLE);
            END LOOP CLOCK_LOOP;
        END PROCESS;

        PROCESS
            PROCEDURE CHECK_qout(
                next_qout : std_logic_vector (7 DownTo 0);
                TX_TIME : INTEGER
            ) IS
                VARIABLE TX_STR : String(1 to 4096);
                VARIABLE TX_LOC : LINE;
                BEGIN
                IF (qout /= next_qout) THEN
                    STD.TEXTIO.write(TX_LOC, string'("Error at time="));
                    STD.TEXTIO.write(TX_LOC, TX_TIME);
                    STD.TEXTIO.write(TX_LOC, string'("ns qout="));
                    IEEE.STD_LOGIC_TEXTIO.write(TX_LOC, qout);
                    STD.TEXTIO.write(TX_LOC, string'(", Expected = "));
                    IEEE.STD_LOGIC_TEXTIO.write(TX_LOC, next_qout);
                    STD.TEXTIO.write(TX_LOC, string'(" "));
                    TX_STR(TX_LOC.all'range) := TX_LOC.all;
                    STD.TEXTIO.writeline(RESULTS, TX_LOC);
                    STD.TEXTIO.Deallocate(TX_LOC);
                    ASSERT (FALSE) REPORT TX_STR SEVERITY ERROR;
                    TX_ERROR := TX_ERROR + 1;
                END IF;
            END;
            BEGIN
                -- -------------  Current Time:  25ns
                WAIT FOR 25 ns;
                din <= '1';
                -- -------------------------------------
                -- -------------  Current Time:  105ns
                WAIT FOR 80 ns;
                din <= '0';
                -- -------------------------------------
                -- -------------  Current Time:  185ns
                WAIT FOR 80 ns;
                din <= '1';
                -- -------------------------------------
                -- -------------  Current Time:  265ns
                WAIT FOR 80 ns;
                din <= '0';
                -- -------------------------------------
                -- -------------  Current Time:  345ns
                WAIT FOR 80 ns;
                din <= '1';
                -- -------------------------------------
                -- -------------  Current Time:  425ns
                WAIT FOR 80 ns;
                din <= '0';
                -- -------------------------------------
                -- -------------  Current Time:  505ns
                WAIT FOR 80 ns;
                din <= '1';
                -- -------------------------------------
                -- -------------  Current Time:  585ns
                WAIT FOR 80 ns;
                din <= '0';
                -- -------------------------------------
                -- -------------  Current Time:  665ns
                WAIT FOR 80 ns;
                din <= '1';
                -- -------------------------------------
                -- -------------  Current Time:  745ns
                WAIT FOR 80 ns;
                din <= '0';
                -- -------------------------------------
                -- -------------  Current Time:  825ns
                WAIT FOR 80 ns;
                din <= '1';
                -- -------------------------------------
                -- -------------  Current Time:  905ns
                WAIT FOR 80 ns;
                din <= '0';
                -- -------------------------------------
                -- -------------  Current Time:  985ns
                WAIT FOR 80 ns;
                din <= '1';
                WAIT FOR 95 ns;

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

