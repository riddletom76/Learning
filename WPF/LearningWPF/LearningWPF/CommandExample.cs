using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Input;

namespace LearningWPF
{
    public class CommandExample : ICommand
    {
        private Action<object> executeCommand;
        private Func<object, bool> canexecuteCommand;
        public CommandExample(Action<object> execute, Func<object, bool> canExecute)
        {
            this.executeCommand = execute;
            this.canexecuteCommand = canExecute;
        }
        public event EventHandler CanExecuteChanged;

        public bool CanExecute(object parameter)
        {
            return canexecuteCommand(parameter);
        }

        public void Execute(object parameter)
        {
            executeCommand(parameter);
        }
    }
}
