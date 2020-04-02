----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    11:31:48 08/22/2017 
-- Design Name: 
-- Module Name:    mux8_1 - Behavioral 
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

entity mux8_1 is
    Port ( id : in  STD_LOGIC_VECTOR (7 downto 0);
           se : in  STD_LOGIC_VECTOR (2 downto 0);
        
           yy : out  STD_LOGIC);
end mux8_1;

architecture Behavioral of mux8_1 is

component mux4 is
Port ( i : in  STD_LOGIC_VECTOR (3 downto 0);
           s : in  STD_LOGIC_VECTOR (1 downto 0);
			  e : in  STD_LOGIC;
           y : out  STD_LOGIC);
end component;			  

signal x1,x2,ns2:STD_LOGIC;
begin
ns2<= not se(2);
mux4_0: mux4 port map(i(0)=>id(0),i(1)=>id(1),i(2)=>id(2),i(3)=>id(3),s(0)=>se(0),s(1)=>se(1),e=>ns2,y=>x1);
mux4_1: mux4 port map(i(0)=>id(4),i(1)=>id(5),i(2)=>id(6),i(3)=>id(7),s(0)=>se(0),s(1)=>se(1),e=>se(2),y=>x2);	
yy<=x1 or x2;
end Behavioral;

