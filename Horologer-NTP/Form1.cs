using System.ComponentModel;
using System.Diagnostics;
using System.Net.NetworkInformation;
using static Horologer_NTP.AboutBox1;
using static Horologer_NTP.Program;
namespace Horologer_NTP
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
            var worker = new BackgroundWorker();
            worker.DoWork += new DoWorkEventHandler(threadwork);
            worker.RunWorkerAsync();
            //Stopwatcher();
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
            DateTime server = GetNetworkTime("time.windows.com");
            time.Text = server.ToLocalTime().ToString("hh:mm:ss tt");
        }

        public async Task Stopwatcher()
        {
            while (true)
            {
                var delayTask = Task.Delay(1000);
                UpdateTime();
                await delayTask; // wait until at least 10s elapsed since delayTask created
            }
        }

        void threadwork(object sender, DoWorkEventArgs e)
        {
            while (true)
            {
                System.Threading.Thread.Sleep(100);
                DateTime server = GetNetworkTime("time.windows.com");
                //Pinger("time.windows.com");
                //time.Text = server.ToLocalTime().ToString("hh:mm:ss tt");
                this.time.Invoke((MethodInvoker)delegate { time.Text = server.ToLocalTime().ToString("hh:mm:ss tt"); });
                //UpdateTime();
            }
        }
    }
}