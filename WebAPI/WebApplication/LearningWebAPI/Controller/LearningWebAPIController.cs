using System.Collections.Generic;
using System.Web.Http;

namespace LearningWebAPI.Controller
{
    public class LearningWebAPIController : ApiController
    {
        static List<string> values = new List<string>()
        {
            "value0", "value1", "value2"
        };
        public IEnumerable<string> Get()
        {
            return values;
        }

        public string Get(int id)
        {
            return values[id];
        }

        public void Post([FromBody] string message)
        {
            values.Add(message);
        }

        public void Put(int id, [FromBody] string message)
        {
            values[id] = message;
        }

        public void Delete(int id)
        {
            values.RemoveAt(id);
        }

    }
}
