using System.ComponentModel;
using System.Diagnostics;
using System.Net.NetworkInformation;
using static Horologer_NTP.AboutBox1;
using static Horologer_NTP.Program;
using static Horologer_NTP.IniFile;
namespace Horologer_NTP
{
    public partial class Form1 : Form
    {
        static IniFile myini = new IniFile("config.ini");
        public static string NTP = myini.Read("NTP", "settings");
        public Form1()
        {
            InitializeComponent();
        }

        private void time_Click(object sender, EventArgs e)
        {
        }

        private void label1_Click(object sender, EventArgs e)
        {

        }

        private void aboutToolStripMenuItem_Click(object sender, EventArgs e)
        {
            if (!aboutOpen) {
                new AboutBox1().Show();
                aboutOpen = true;
            }
        }
        public void UpdateTime()
        {
            DateTime server = GetNetworkTime2(NTP);
            accuracyMS.Text = Beancounter(server).ToString("+#;-#;0") + " ms";
            time.Text = server.ToLocalTime().ToString("hh:mm:ss tt");
        }
        public double Beancounter(DateTime server)
        {
            long serverlong = new DateTimeOffset(server).ToUnixTimeMilliseconds();
            long locallong = new DateTimeOffset(DateTime.Now).ToUnixTimeMilliseconds();
            return (double)locallong - serverlong;
        }
        public void UpdatePing(double ping)
        {
            lagMS.Text = ping.ToString() + " ms";
        }

        public async Task Stopwatcher()
        {
            while (true)
            {
                var delayTask = Task.Delay(500);
                UpdateTime();
                await delayTask; // wait until at least 10s elapsed since delayTask created
            }
        }

        public async Task Pingwatcher()
        {
            while (true)
            {
                var delayTask = Task.Delay(500);
                //0.north-america.pool.ntp.org
                UpdatePing(Pinger(NTP));
                await delayTask;
            }
        }

        private void Form1_Shown(object sender, EventArgs e)
        {
            Stopwatcher();
            Pingwatcher();
            //BackgroundWorker bgPing = new BackgroundWorker();
            //bgPing.DoWork += Workerping;
            //bgPing.RunWorkerAsync();
        }

        private void Workerping(object sender, DoWorkEventArgs e)
        {
            while (true)
            {
                //string ip = myini.Read("NTP", "settings");
                //0.north-america.pool.ntp.org
                //UpdatePing(Pinger(NTP));
                lagMS.Invoke((MethodInvoker)delegate
                {
                    lagMS.Text = Pinger(NTP).ToString() + " ms";
                });
                Thread.Sleep(1000);
            }
        }
    }
}