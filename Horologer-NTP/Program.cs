using System.Net;
using System.Net.NetworkInformation;
using System.Net.Sockets;
using static Horologer_NTP.Form1;

namespace Horologer_NTP
{
    internal static class Program
    {
        /// <summary>
        ///  The main entry point for the application.
        /// </summary>
        [STAThread]
        static void Main()
        {
            // To customize application configuration such as set high DPI settings or default font,
            // see https://aka.ms/applicationconfiguration.
            ApplicationConfiguration.Initialize();
            Form1 main = new Form1();
            Application.Run(main);
            main.UpdateTime();

        }
        public static double Pinger(string IP)
        {
            Ping NTP = new Ping();
            PingReply pingReplyping = NTP.Send(IP);
            //Console.WriteLine("Status :  " + pingReplyping.Status + 
            //" \n Time : " + pingReplyping.RoundtripTime.ToString() + 
            //" \n Address : " + pingReplyping.Address);
            return pingReplyping.RoundtripTime;
            //return pingReplyping.RoundtripTime;
        }

        public static DateTime GetNetworkTime(string ip)
        {
            string ntpServer = ip;
            //"time.windows.com";
            var ntpData = new byte[48];
            ntpData[0] = 0x1B; //LeapIndicator = 0 (no warning), VersionNum = 3 (IPv4 only), Mode = 3 (Client Mode)

            var addresses = Dns.GetHostEntry(ntpServer).AddressList;
            var ipEndPoint = new IPEndPoint(addresses[0], 123);
            var socket = new Socket(AddressFamily.InterNetwork, SocketType.Dgram, ProtocolType.Udp);

            socket.Connect(ipEndPoint);
            socket.Send(ntpData);
            socket.Receive(ntpData);
            socket.Close();
            //if (!socket.Connected)
            //{
            //    return DateTime.Now;
            //}

            ulong intPart = (ulong)ntpData[40] << 24 | (ulong)ntpData[41] << 16 | (ulong)ntpData[42] << 8 | (ulong)ntpData[43];
            ulong fractPart = (ulong)ntpData[44] << 24 | (ulong)ntpData[45] << 16 | (ulong)ntpData[46] << 8 | (ulong)ntpData[47];

            var milliseconds = (intPart * 1000) + ((fractPart * 1000) / 0x100000000L);
            var networkDateTime = (new DateTime(1900, 1, 1)).AddMilliseconds((long)milliseconds);

            return networkDateTime;
        }
    }
}