----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    11:17:22 10/10/2017 
-- Design Name: 
-- Module Name:    8_SISO - Behavioral 
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

entity Bit_8_SISO is
    Port ( din : in  STD_LOGIC;
           clk : in  STD_LOGIC;
           cout : out  STD_LOGIC);
end Bit_8_SISO;


architecture Behavioral of Bit_8_SISO is
component DFF is
    Port ( d : in  STD_LOGIC;
           clk : in  STD_LOGIC;
           q : out  STD_LOGIC);
end component;
signal x0,x1,x2,x3,x4,x5,x6 : STD_LOGIC;


begin

	d0: DFF port map (d=>din,clk=>clk,q=>x0);
	d1: DFF port map (d=>x0,clk=>clk,q=>x1);
	d2: DFF port map (d=>x1,clk=>clk,q=>x2);
	d3: DFF port map (d=>x2,clk=>clk,q=>x3);
	d4: DFF port map (d=>x3,clk=>clk,q=>x4);
	d5: DFF port map (d=>x4,clk=>clk,q=>x5);
	d6: DFF port map (d=>x5,clk=>clk,q=>x6);
	d7: DFF port map (d=>x6,clk=>clk,q=>cout);


end Behavioral;

