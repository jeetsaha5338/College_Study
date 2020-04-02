----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    11:52:43 08/01/2017 
-- Design Name: 
-- Module Name:    fulladder4bit - Behavioral 
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

entity fulladder4bit is
    Port ( a : in  STD_LOGIC_VECTOR (3 downto 0);
           b : in  STD_LOGIC_VECTOR (3 downto 0);
           cin : in  STD_LOGIC;
           s : out  STD_LOGIC_VECTOR (3 downto 0);
           cout : out  STD_LOGIC);
end fulladder4bit;

architecture Behavioral of fulladder4bit is
component fulladder 
	Port (a: in STD_LOGIC_Vector(2 downto 0);
			s: out STD_LOGIC;
			c: out STD_LOGIC);
end component;

signal c1,c2,c3: STD_LOGIC;
begin
fulladder0: fulladder Port map(a(0)=>a(0),a(1)=>b(0),a(2)=>cin,s=>s(0),c=>c1);
fulladder1: fulladder Port map(a(0)=>a(1),a(1)=>b(1),a(2)=>c1,s=>s(1),c=>c2);
fulladder2: fulladder Port map(a(0)=>a(2),a(1)=>b(2),a(2)=>c2,s=>s(2),c=>c3);
fulladder4: fulladder Port map(a(0)=>a(3),a(1)=>b(3),a(2)=>c3,s=>s(3),c=>cout);

end Behavioral;

