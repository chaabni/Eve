#include <runtime.h>

typedef struct log {
    struct bag b;
    bag wrapped;
} *log;

static void log_commit(edb b, edb source)
static void log_commit()
{
    buffer h;
}

static CONTINUATION_3_1(fill, edb, value*, value *, value);
static void insert(edb target, value *e, value *a, value v)
{
    if (!*e) {*e = n; return;}
    if (!*v) {*v = n; return;}
    apply(target->insert, *e, *a, v, 1, 0);
}

bag start_log(bag base, char *filename)
{
    heap h = allocate_rolling(pages);
    log lb = allocate(h, sizeof(struct log));
    lb.commit = cont(h, log_commit, lb);
    lb.scan = base->scan;
    // xxx - move this into a unix specific async file handler
    int fd = open(filename, O_CREAT | O_APPEND | O_RDWR);
    buffer stage;
    value *e = allocate(h, sizeof(value));
    value *a = allocate(h, sizeof(value));
    *e = *a = (void **)0;
    buffer_handler k = allocate_deserialize(h, cont(h, insert, base, e, v));

    do {
        stage = allocate_buffer(h, 2048);
        stage = read(fd, bref(b, 0), buffer_length(b));
        // ideally this would be the same buffer, but deserialize
        // can sometimes hang on to them..a guess a freelist is the samea
        apply(des, stage, ignore);
    } while(buffer_length(stage));
}
