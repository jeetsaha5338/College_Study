----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    16:16:37 09/08/2017 
-- Design Name: 
-- Module Name:    CLA - Behavioral 
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

entity CLA is
    Port ( A : in  STD_LOGIC_VECTOR (3 downto 0);
           B : in  STD_LOGIC_VECTOR (3 downto 0);
           CIN : in  STD_LOGIC;
           S : out  STD_LOGIC_VECTOR (3 downto 0);
           COUT : out  STD_LOGIC);
end CLA;

architecture Behavioral of CLA is

signal G,P : STD_LOGIC_VECTOR (3 downto 0);
signal C : STD_LOGIC_VECTOR (4 downto 0);

begin

	sum_pr: Process (A,B,CIN,C)
		begin
			S(0)<=A(0) xor B(0) xor CIN;
				for i in 3 downto 1 loop
					S(i)<=A(i) xor B(i) xor C(i);
				end loop;
			end process;
			
		gen_pr:Process(A,B)
			begin
				for i in 3 downto 0 loop
					G(i)<=A(i)and B(i);
				end loop;
			end Process;
			
		prop_pr:Process(A,B)
			begin
				for i in 3 downto 0 loop
					P(i)<=A(i)XOR B(i);
				end loop;
			end Process;
		carry_pr:Process(G,P,CIN,C)
			begin
				C(0)<=CIN;
				for i in 4 downto 1 loop
					C(i)<=G(i-1) xor (P(i-1)and C(i-1));
				end loop;
			end Process;
		COUT<=C(4);	
end Behavioral;

