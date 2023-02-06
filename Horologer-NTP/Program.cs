using System.Net.NetworkInformation;
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
        static Array Ping(string IP)
        {
            Ping NTP = new Ping();
            PingReply pingReplyping = NTP.Send(IP);
            Console.WriteLine("Status :  " + pingReplyping.Status + 
            " \n Time : " + pingReplyping.RoundtripTime.ToString() + 
            " \n Address : " + pingReplyping.Address);
            string[] array = { pingReplyping.RoundtripTime.ToString(), pingReplyping.Status.ToString() };
            return array;
            //return pingReplyping.RoundtripTime;
        }
    }
}