----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    11:16:05 08/29/2017 
-- Design Name: 
-- Module Name:    ALU - Behavioral 
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

entity ALU is
    Port ( A : in  STD_LOGIC_VECTOR (3 downto 0);
           b : in  STD_LOGIC_VECTOR (3 downto 0);
           cin : in  STD_LOGIC;
           se : in  STD_LOGIC_VECTOR (1 downto 0);
           sum : out  STD_LOGIC_VECTOR (3 downto 0);
           cout : out  STD_LOGIC);
end ALU;

architecture Behavioral of ALU is

component mux4 is 
	Port (  i : in  STD_LOGIC_VECTOR (3 downto 0);
           s : in  STD_LOGIC_VECTOR (1 downto 0);
			  e : in  STD_LOGIC;
           y : out  STD_LOGIC);
end component;

component Full_Add is
    Port ( a : in  STD_LOGIC_VECTOR (2 downto 0);
           s : out  STD_LOGIC;
           c  : out  STD_LOGIC);
end component;

signal c1,c2,c3,n0,n1,n2,n3,nb0,nb1,nb2,nb3: STD_LOGIC;


begin
nb0<=not b(0);
nb1<=not b(1);
nb2<=not b(2);
nb3<=not b(3);
mux40: mux4 port map(i(0)=>b(0),i(1)=>nb0,i(2)=>'1',i(3)=>'0',s(0)=>se(0),s(1)=>se(1),e=>'1',y=>n0);
mux41: mux4 port map(i(0)=>b(1),i(1)=>nb1,i(2)=>'1',i(3)=>'0',s(0)=>se(0),s(1)=>se(1),e=>'1',y=>n1);
mux42: mux4 port map(i(0)=>b(2),i(1)=>nb2,i(2)=>'1',i(3)=>'0',s(0)=>se(0),s(1)=>se(1),e=>'1',y=>n2);
mux43: mux4 port map(i(0)=>b(3),i(1)=>nb3,i(2)=>'1',i(3)=>'0',s(0)=>se(0),s(1)=>se(1),e=>'1',y=>n3);



Full_Add0 : Full_Add port map (a(0)=>n0,a(1)=>A(0),a(2)=>cin,s=>sum(0),c=>c1);
Full_Add1 : Full_Add port map (a(0)=>n1,a(1)=>A(1),a(2)=>c1,s=>sum(1),c=>c2);
Full_Add2 : Full_Add port map (a(0)=>n2,a(1)=>A(2),a(2)=>c2,s=>sum(2),c=>c3);
Full_Add3 : Full_Add port map (a(0)=>n3,a(1)=>A(3),a(2)=>c3,s=>sum(3),c=>cout);

end Behavioral;

