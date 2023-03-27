using System.ComponentModel;
using static Horologer_NTP.AboutBox1;
using static Horologer_NTP.Program;
using static Horologer_NTP.settingsForm;

namespace Horologer_NTP
{
    public partial class Form1 : Form
    {
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
            if (!aboutOpen)
            {
                new AboutBox1().Show();
                aboutOpen = true;
            }
        }
        public void UpdateTime()
        {
            DateTime server = GetNetworkTime2(Properties.Settings1.Default.NTPserver);
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
                var delayTask = Task.Delay(300, default);
                UpdateTime();
                await delayTask; // wait until at least 10s elapsed since delayTask created
            }
        }

        public async Task Pingwatcher()
        {
            while (true)
            {
                var delayTask = Task.Delay(1000, default);
                //0.north-america.pool.ntp.org
                UpdatePing(await Pinger(Properties.Settings1.Default.NTPserver));
                await delayTask;
            }
        }
        private void Form1_Shown(object sender, EventArgs e)
        {
            Stopwatcher();
            Pingwatcher();
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
                    lagMS.Text = Pinger(Properties.Settings1.Default.NTPserver).ToString() + " ms";
                });
                Thread.Sleep(1000);
            }
        }

        private void settingsToolStripMenuItem_Click(object sender, EventArgs e)
        {
            if (!SettOpen)
            {
                new settingsForm().Show();
                SettOpen = true;
            }
        }
    }
}