----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    12:02:24 10/10/2017 
-- Design Name: 
-- Module Name:    SIPO - Behavioral 
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

entity SIPO is
    Port ( din : in  STD_LOGIC;
           clk : in  STD_LOGIC;
           qout : out  STD_LOGIC_VECTOR (7 downto 0));
end SIPO;

architecture Behavioral of SIPO is
component DFF is
    Port ( d : in  STD_LOGIC;
           clk : in  STD_LOGIC;
           cout : out  STD_LOGIC);
end component;
signal x0,x1,x2,x3,x4,x5,x6 : STD_LOGIC;
begin

	d0: DFF port map (d=>din,clk=>clk,cout=>x0);
	qout(0)<=x0;
	d1: DFF port map (d=>x0,clk=>clk,cout=>x1);
	qout(1)<=x1;
	d2: DFF port map (d=>x1,clk=>clk,cout=>x2);
	qout(2)<=x2;
	d3: DFF port map (d=>x2,clk=>clk,cout=>x3);
	qout(3)<=x3;
	d4: DFF port map (d=>x3,clk=>clk,cout=>x4);
	qout(4)<=x4;
	d5: DFF port map (d=>x4,clk=>clk,cout=>x5);
	qout(5)<=x5;
	d6: DFF port map (d=>x5,clk=>clk,cout=>x6);
	qout(6)<=x6;
	d7: DFF port map (d=>x6,clk=>clk,cout=>qout(7));


end Behavioral;

