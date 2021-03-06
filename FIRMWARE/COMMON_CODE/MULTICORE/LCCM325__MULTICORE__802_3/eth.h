/**
 * @file		eth.h
 * @brief		Ethernet main header file
 * @author		Lachlan Grogan
 * @copyright	This file contains proprietary and confidential information of the Lockie Group
 *				of companies, including Lockie Innovation Pty. Ltd (ACN 123 529 064) and
 *				Lockie Safety Systems Pty. Ltd (ACN 132 340 571).  This code may be distributed
 *				under a license from the Lockie Group of companies, and may be used, copied
 *				and/or disclosed only pursuant to the terms of that license agreement.
 *				This copyright notice must be retained as part of this file at all times.
 * @copyright	This file is copyright Lockie Innovation Pty Ltd 2003-2012, All Rights Reserved.
 * @copyright	This file is copyright Lockie Safety Systems Pty Ltd 2008-2012, All Rights Reserved.
 * @st_fileID	LCCM325R0.FILE.002
 */

#ifndef _ETH__H_
#define _ETH__H_

	#include <localdef.h>
	#if C_LOCALDEF__LCCM325__ENABLE_THIS_MODULE == 1U
	
		#define C_LCCM325__FIFO_DEPTH			6
	
		/*****************************************************************************
		transmission FIFO
		*****************************************************************************/
		struct _strEUFIFO
		{
		
			//the buffer index we have chosen
			Luint8 u8FIFO_BufferIndex[C_LCCM325__FIFO_DEPTH];
			Luint16 u16FIFO_PacketLength[C_LCCM325__FIFO_DEPTH];
	
			//FIFO Positions
			Luint8 u8FIFO_WritePosition;
			Luint8 u8FIFO_ReadPosition;
					
			//the full flag is set by the write position going to the end.
			Luint8 u8FIFO_Full;
			Luint8 u8FIFO_Empty;
			Luint8 u8FIFO_FillLevel;
		
		};

		/*****************************************************************************
		ethernet structure
		*****************************************************************************/
		struct _strETH
		{

			//is a transmit required?
			Luint8 u8TxRequired;

			//our MAC and IP
			//Set/copied from the EMAC interfacer.
			Luint8 u8MACAddx[6];
			Luint8 u8IPAddx[4];
			

			#if (C_LOCALDEF__SIL3_GENERIC__CPU_TYPE__XILINX_MICROBLAZE == 1U || C_LOCALDEF__SIL3_GENERIC__CPU_TYPE__XILINX_PPC405 == 1U || C_LOCALDEF__SIL3_GENERIC__CPU_TYPE__XILINX_PPC440 == 1U) || (C_LOCALDEF__SIL3_GENERIC__CPU_TYPE__WIN32 == 1U)
			struct
			{
				/** The length of the NPI payload to send */
				Luint32 u32PayloadLength;

				/** The memory addx of the payload to send */
				Luint32 u32PayloadAddx;

			}sXilinx;
			#endif

			/*****************************************************************************
			EthernetII layer
			*****************************************************************************/
			struct
			{
				/** Dest hardware MAC */
				Luint8 u8DestMAC[6U];

				/** Source hardware MAC */
				Luint8 u8SourceMAC[6U];

				/** Ethernet frame type */
				Luint16 u16EtherType;

			}sETH_II;

			
			/*****************************************************************************
			UDP Layer
			*****************************************************************************/
			struct
			{
				Luint16 u16SourcePort;
				Luint16 u16DestPort;
				Luint16 u16Length;
				Luint16 u16Checksum;


			}sUDP;


			/*****************************************************************************
			IPV4 Layer
			*****************************************************************************/
			struct
			{
				/** IPV4 version */
				Luint8 u8Version;
				Luint8 u8InternetHeaderLength;
				Luint16 u16TotalLength;
				Luint8 u8Protocol;
				Luint8 u8SourceIP[4U];
				Luint8 u8DestIP[4U];

				/** If we are using Unicast use this, else it will be FF*/
				Luint8 u8UnicastDestIP[4];

			}sIPV4;

			/*****************************************************************************
			ARP (Address resolution protocol
			*****************************************************************************/
			struct
			{
				Luint8 u8MACAddx[6];
				Luint8 u8IPAddx[4];
			
			}sARP;
			
			#if C_LOCALDEF__LCCM325__ENABLE_DHCP_CLIENT == 1U
			/*****************************************************************************
			DHCP (Dynamic Host Config Protocol)
			*****************************************************************************/
			struct
			{

				#define C_ETH__DHCPCLI_STATE__IDLE										(0U)
				#define C_ETH__DHCPCLI_STATE__DISCOVER									(1U)
				#define C_ETH__DHCPCLI_STATE__WAIT_OFFER								(2U)
				#define C_ETH__DHCPCLI_STATE__OFFER										(3U)
				#define C_ETH__DHCPCLI_STATE__WAIT_REQUEST								(4U)
				#define C_ETH__DHCPCLI_STATE__REQUEST									(5U)
				#define C_ETH__DHCPCLI_STATE__WAIT_ACK									(6U)
				#define C_ETH__DHCPCLI_STATE__ACK										(7U)

				//the current state the DHCP Client is in
				Luint8 u8State;

				Luint8 u8MACAddx[6];
				Luint8 u8IPAddx[4];

			}sDHCP;
			#endif
			
			#ifdef WIN32
			struct
			{
				/** Temp Assy buffer for WIN32 systems */
				Luint8 u8WIN32_AssemblyBuffer[1600];
			}sWIN32;
			#endif

		};
	
	
		//function protos
		void vSIL3_ETH__Init(Luint8 * pu8MAC, Luint8 * pu8IP);
		void vSIL3_ETH__Process(void);
		Luint8 u8SIL3_ETH_FIFO__Is_Empty(void);
		Lint16 s16SIL3_ETH_FIFO__Pop(Luint8 * pu8BufferIndex, Luint16 * pu16PacketLength);
		void vSIL3_ETH_FIFO__Peek(Luint8 u8BufferPos, Luint8 * pu8BufferIndex, Luint16 * pu16PacketLength);
		Lint16 s16SIL3_ETH_FIFO__Push(Luint16 u16PacketLength);
		void vSIL3_ETH_FIFO__Push_UpdateLength(Luint8 u8FIFOIndex, Luint16 u16NewLength);
		void vSIL3_ETH_FIFO__Transmit(void);
		void vSIL3_ETH_FIFO__Reset(void);
		
		#if (C_LOCALDEF__SIL3_GENERIC__CPU_TYPE__RM42L432 == 1U || C_LOCALDEF__SIL3_GENERIC__CPU_TYPE__RM46L852 == 1U || C_LOCALDEF__SIL3_GENERIC__CPU_TYPE__RM48L952 == 1U || C_LOCALDEF__SIL3_GENERIC__CPU_TYPE__RM57L843 == 1U)
			void vSIL3_ETH_FIFO__Transmit_Worker_RM4(void);
		#elif (C_LOCALDEF__SIL3_GENERIC__CPU_TYPE__XILINX_MICROBLAZE == 1U || C_LOCALDEF__SIL3_GENERIC__CPU_TYPE__XILINX_PPC405 == 1U || C_LOCALDEF__SIL3_GENERIC__CPU_TYPE__XILINX_PPC440 == 1U)
			void vSIL3_ETH_XILINX__Init(void);
			void vSIL3_ETH_XILINX__Transmit_PLB(Luint8 u8DeviceIndex);
			#if C_LOCALDEF__LCCM325__XILINX_USE_NPI_INTERFACE == 1U
				void vSIL3_ETH_XILINX__Transmit_NPI(Luint8 u8DeviceIndex);
			#endif
		#elif C_LOCALDEF__SIL3_GENERIC__CPU_TYPE__WIN32 == 1U
			void vSIL3_ETH_FIFO__Transmit_Worker_WIN32(void);
		#elif C_LOCALDEF__SIL3_GENERIC__CPU_TYPE__MSP430F5529 == 1U
			Lint16 s16ETH_FIFO__Transmit_Worker_MSP430(void);
		#else
			#error
		#endif

		//ethernet layer
		void vSIL3_ETH_ETH2__Init(void);
		void vSIL3_ETH_ETH2__Process(void);
		void vSIL3_ETH_ETH2__Input(Luint8 * pu8Buffer);
		void vSIL3_ETH_ETH2__Transmit(Luint16 u16EtherType, Luint8 * pu8DestMAC);
	
		//ipv4 layer
		void vSIL3_ETH_IPV4__Init(void);
		void vSIL3_ETH_IPV4__Process(void);
		void vSIL3_ETH_IPV4__Input(Luint8 * pu8Buffer);
		void vSIL3_ETH_IPV4__Transmit(Luint16 u16Length);
		void vSIL3_ETH_IPV4__Set_UnicastAddx(Luint8 *pu8Addx);
	
		//ARP
		void vSIL3_ETH_ARP__Init(void);
		void vSIL3_ETH_ARP__Process(void);
		void vSIL3_ETH_ARP__Input(Luint8 * pu8Buffer);
		void vSIL3_ETH_ARP__Reply(void);
		void vSIL3_ETH_ARP__Gratuitous(void);
		
		//SNMP
		#if C_LOCALDEF__LCCM325__ENABLE_SNMP == 1U
			void vSIL3_ETH_SNMP__Init(void);
			void vSIL3_ETH_SNMP__Process(void);
			void vSIL3_ETH_SNMP__Input(Luint8 * pu8Buffer);
			void vSIL3_ETH_SNMP__Transmit(Luint16 *pu16OID, Luint8 u8OIDLength, Luint8 u8RequestType);
		#endif

		//udp
		void vSIL3_ETH_UDP__Init();
		void vSIL3_ETH_UDP__Transmit(Luint16 u16Length, Luint16 u16SourcePort, Luint16 u16DestPort);
		#if (C_LOCALDEF__SIL3_GENERIC__CPU_TYPE__XILINX_MICROBLAZE == 1U || C_LOCALDEF__SIL3_GENERIC__CPU_TYPE__XILINX_PPC405 == 1U || C_LOCALDEF__SIL3_GENERIC__CPU_TYPE__XILINX_PPC440 == 1U) || (C_LOCALDEF__SIL3_GENERIC__CPU_TYPE__WIN32 == 1U)
			#if C_LOCALDEF__LCCM325__XILINX_USE_NPI_INTERFACE == 1U
				void vSIL3_ETH_UDP__Transmit_WithPayload(Luint16 u16Length, Luint16 u16SourcePort, Luint16 u16DestPort, Luint32 u32PayloadLength, Luint32 u32PayloadAddx);
			#endif
		#endif
		void vSIL3_ETH_UDP__Input(Luint8 * pu8Buffer);
		
		//DHCP
		#if C_LOCALDEF__LCCM325__ENABLE_DHCP_CLIENT == 1U

		#endif

		//LLDP
		#if C_LOCALDEF__LCCM325__ENABLE_LLDP == 1U
			void vSIL3_ETH_LLDP__Init(void);
			void vSIL3_ETH_LLDP__Process(void);
			void vSIL3_ETH_LLDP__Input(Luint8 * pu8Buffer);
			void vSIL3_ETH_LLDP__TransmitFrame(void);
		#endif

		//buffer desc
		Luint32 u32SIL3_ETH_BUFFERDESC__Get_TxBufferPointer(Luint8 u8BufferIndex);
		Luint16 u16SIL3_ETH_BUFFERDESC__Get_BufferSize(Luint8 u8BufferIndex);
		void vSIL3_ETH_BUFFERDESC__Set_Length(Luint8 u8BufferIndex, Luint32 u32Length);
		
		#ifdef WIN32
			void vSIL3_ETH_WIN32__Init(void);
			//declare the type
			typedef void (__cdecl * pETH_WIN32__TxCallback_FuncType)(Luint8 * pu8Buffer, Luint16 u16BufferLength);
			DLL_DECLARATION void vSIL3_ETH_WIN32__Set_Ethernet_TxCallback(pETH_WIN32__TxCallback_FuncType pFunc);
			DLL_DECLARATION void vSIL3_ETH_WIN32__Ethernet_Input(Luint8 * pu8Buffer, Luint16 u16BufferLength);
			DLL_DECLARATION void vSIL3_ETH_WIN32__Ethernet_Output(Luint8 * pu8Buffer, Luint16 u16BufferLength);
		#endif		
		
		//testing
		#if C_LOCALDEF__LCCM325__ENABLE_TEST_SPEC == 1U
			void vLCCM325R0_TS_001(void);
			void vLCCM325R0_TS_002(void);
			void vLCCM325R0_TS_003(void);
			void vLCCM325R0_TS_004(void);
			void vLCCM325R0_TS_005(void);
			void vLCCM325R0_TS_006(void);
			void vLCCM325R0_TS_007(void);
			void vLCCM325R0_TS_008(void);
			void vLCCM325R0_TS_009(void);
			void vLCCM325R0_TS_010(void);
			void vLCCM325R0_TS_011(void);
			void vLCCM325R0_TS_012(void);
			void vLCCM325R0_TS_013(void);
			void vLCCM325R0_TS_014(void);
			void vLCCM325R0_TS_015(void);
			void vLCCM325R0_TS_016(void);
			void vLCCM325R0_TS_017(void);
			void vLCCM325R0_TS_018(void);
			void vLCCM325R0_TS_019(void);
			void vLCCM325R0_TS_020(void);
			void vLCCM325R0_TS_021(void);
			void vLCCM325R0_TS_022(void);
			void vLCCM325R0_TS_023(void);
			void vLCCM325R0_TS_024(void);
			void vLCCM325R0_TS_025(void);
			DLL_DECLARATION void vLCCM325R0_TS_026(void);
			void vLCCM325R0_TS_027(void);
			void vLCCM325R0_TS_028(void);
			void vLCCM325R0_TS_029(void);
			DLL_DECLARATION void vLCCM325R0_TS_040(void);
		#endif
	
	#endif //C_LOCALDEF__LCCM325__ENABLE_THIS_MODULE
	#ifndef C_LOCALDEF__LCCM325__ENABLE_THIS_MODULE
		#error
	#endif
	



#endif //_ETH__H_


