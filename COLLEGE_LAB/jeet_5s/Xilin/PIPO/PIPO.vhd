----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    12:31:58 10/10/2017 
-- Design Name: 
-- Module Name:    PIPO - Behavioral 
-- Project Name: 
-- Target Devices: 
-- Tool versions: 
-- Description: 
--
-- Dependencies: 
--
-- Revision: 
-- Revision 0.01 - File Created
-- Additional Comments: 
--
----------------------------------------------------------------------------------
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.STD_LOGIC_ARITH.ALL;
use IEEE.STD_LOGIC_UNSIGNED.ALL;

---- Uncomment the following library declaration if instantiating
---- any Xilinx primitives in this code.
--library UNISIM;
--use UNISIM.VComponents.all;

entity PIPO is
    Port ( din : in  STD_LOGIC_VECTOR (7 downto 0);
           clk : in  STD_LOGIC;
           qout : out  STD_LOGIC_VECTOR (7 downto 0));
end PIPO;

architecture Behavioral of PIPO is


component DFF is
    Port ( d : in  STD_LOGIC;
           clk : in  STD_LOGIC;
           cout : out  STD_LOGIC);
end component;


begin

	d0: DFF port map (d=>din(0),clk=>clk,cout=>qout(0));
	d1: DFF port map (d=>din(1),clk=>clk,cout=>qout(1));
	d2: DFF port map (d=>din(2),clk=>clk,cout=>qout(2));
	d3: DFF port map (d=>din(3),clk=>clk,cout=>qout(3));
	d4: DFF port map (d=>din(4),clk=>clk,cout=>qout(4));
	d5: DFF port map (d=>din(5),clk=>clk,cout=>qout(5));
	d6: DFF port map (d=>din(6),clk=>clk,cout=>qout(6));
	d7: DFF port map (d=>din(7),clk=>clk,cout=>qout(7));


end Behavioral;

